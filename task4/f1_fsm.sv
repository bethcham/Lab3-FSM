module f1_fsm(
    input logic         clk,
    input logic         rst,
    input logic         en,
    input logic         trigger,
    output logic [7:0]  data_out,
    output logic        cmd_seq,
    output logic        cmd_delay
);

    typedef enum {S0, S1, S2, S3, S4, S5, S6, S7, S8} mystate;
    mystate current_state, next_state;

always_comb
    case (current_state)
        S0: begin
            next_state = S1;
            data_out = 8'b0;
            cmd_delay = 0;
            cmd_seq = 0;
        end
        S1: begin
            next_state = S2;
            data_out = 8'b1;
            cmd_delay = 0;
            cmd_seq = 1;
        end
        S2: begin
            next_state = S3;
            data_out = 8'b11;
            cmd_delay = 0;
            cmd_seq = 1;
        end
        S3: begin
            next_state = S4;
            data_out = 8'b111;
            cmd_delay = 0;
            cmd_seq = 1;
        end
        S4: begin
            next_state = S5;
            data_out = 8'b1111;
            cmd_delay = 0;
            cmd_seq = 1;
        end
        S5: begin
            next_state = S6;
            data_out = 8'b11111;
            cmd_delay = 0;
            cmd_seq = 1;
        end
        S6: begin
            next_state = S7;
            data_out = 8'b111111;
            cmd_delay = 0;
            cmd_seq = 1;
        end
        S7: begin
            next_state = S8;
            data_out = 8'b1111111;
            cmd_delay = 0;
            cmd_seq = 1;
        end
        S8: begin
            next_state = S0;
            data_out = 8'b11111111;
            cmd_delay = 1;
            cmd_seq = 1;
        end
        default: begin
            next_state = S0;
            data_out = 8'b0;
            cmd_delay = 0;
            cmd_seq = 0;
        end
    endcase

// always_comb
//     case (current_state)
//         S0: data_out = 8'b0, cmd_seq = 0;
//         S1: data_out = 8'b1, cmd_seq = 1;
//         S2: data_out = 8'b11, cmd_seq = 1;
//         S3: data_out = 8'b111, cmd_seq = 1;
//         S4: data_out = 8'b1111, cmd_seq = 1;
//         S5: data_out = 8'b11111, cmd_seq = 1;
//         S6: data_out = 8'b111111, cmd_seq = 1;
//         S7: data_out = 8'b1111111, cmd_seq = 1;
//         S8: data_out = 8'b11111111, cmd_seq = 1;
//         default: data_out = 8'b0;
//     endcase
    
always_ff @ (posedge clk, posedge rst)
    if (rst)    current_state <= S0;
    else if (trigger) current_state <= S1;
    else if (en)       current_state <= next_state;

endmodule
