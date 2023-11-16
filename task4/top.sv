module top #(
    parameter WIDTH = 16
)(
    input  logic             clk,      // clock 
    input  logic             rst,      // reset
    input  logic             trigger,
    input  logic [WIDTH-1:0] N,        // clock divided by N+1
    output logic             time_out,
    output logic [7:0]       data_out  // output
);

logic tick;
logic cmd_seq;
logic cmd_delay;
logic [7:0] lfsr_data;

f1_fsm FSM (
    .clk (clk),
    .rst (rst),
    .en (tick), // Use the tick from the clktick module as the "oneshot enable" for going to "next state"
    .trigger (trigger),
    .data_out (data_out),
    .cmd_seq(cmd_seq),
    .cmd_delay(cmd_delay)
);

clktick clock (
    .clk (clk),
    .rst (rst),
    .en (cmd_seq),
    .N (N),
    .tick (tick)
);

lfsr LFSR (
    .clk (clk),
    .rst (rst),
    .data_out(lfsr_data)
);

delay DELAY(
    .clk (clk),
    .rst (rst),
    .trigger (cmd_delay),
    .n (lfsr_data),
    .time_out (time_out)
);

endmodule
