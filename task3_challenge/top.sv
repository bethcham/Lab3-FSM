module top #(
    parameter WIDTH = 16
)(
    input  logic             clk,      // clock 
    input  logic             rst,      // reset
    input  logic             en,       // enable signal
    input  logic [WIDTH-1:0] N,        // clock divided by N+1
    output logic [7:0]       data_out  // output
);

logic tick;

f1_fsm FSM (
    .clk (clk),
    .rst (rst),
    .en (tick), // Use the tick from the clktick module as the "oneshot enable" for going to "next state"
    .data_out (data_out)
);

clktick clock (
    .clk (clk),
    .rst (rst),
    .en (en),
    .N (N),
    .tick (tick)
);

endmodule