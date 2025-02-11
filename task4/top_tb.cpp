#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vtop.h"

#include "vbuddy.cpp"     // include vbuddy code
#define MAX_SIM_CYC 100000

int main(int argc, char **argv, char **env) {
  int simcyc;     // simulation clock count
  int tick;       // each clk cycle has two ticks for two edges
  int lights = 0; // state to toggle LED lights

  Verilated::commandArgs(argc, argv);
  // init top verilog instance
  Vtop * top = new Vtop;
  // init trace dump
  Verilated::traceEverOn(true);
  VerilatedVcdC* tfp = new VerilatedVcdC;
  top->trace (tfp, 99);
  tfp->open ("top.vcd");
 
  // init Vbuddy
  if (vbdOpen()!=1) return(-1);
  vbdHeader("L3T4:F1");
  vbdSetMode(1);        // Flag mode set to one-shot

  // initialize simulation inputs
  top->clk = 1;
  top->rst = 1;
  top->trigger = 0;
  top->N = 27;
  
  // run simulation for MAX_SIM_CYC clock cycles
  for (simcyc=0; simcyc<MAX_SIM_CYC; simcyc++) {
    // dump variables into VCD file and toggle clock
    for (tick=0; tick<2; tick++) {
      tfp->dump (2*simcyc+tick);
      top->clk = !top->clk;
      top->eval ();
    }
    
    //when lights turn off
    if(top->time_out) {
      vbdBar(0);
      vbdInitWatch();
      bool reaction = false; 
      while(!reaction){
        reaction = vbdFlag();
      }
      vbdHeader("Reaction Time:");
      top->data_out = vbdElapsed();
      vbdHex(2, (top->data_out >> 4) & 0xF); // Added line to display two digits
      vbdHex(1, top->data_out & 0xF);
      exit(0);
    }

    vbdHex(2, (top->data_out >> 4) & 0xF); // Added line to display two digits
    vbdHex(1, top->data_out & 0xF);
    vbdBar(top->data_out & 0xFF);

    // set up input signals of testbench
    top->rst = (simcyc < 2);    // assert reset for 1st cycle
    top->trigger = (simcyc == 2);
    vbdCycle(simcyc);

    if (Verilated::gotFinish())  exit(0);
  }

  vbdClose();     // ++++
  tfp->close(); 
  exit(0);
}
