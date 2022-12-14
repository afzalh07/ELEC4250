// ==============================================================
// RTL generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2019.1
// Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

(* CORE_GENERATION_INFO="m_add,hls_ip_2019_1,{HLS_INPUT_TYPE=c,HLS_INPUT_FLOAT=0,HLS_INPUT_FIXED=0,HLS_INPUT_PART=xczu3eg-sbva484-1-i,HLS_INPUT_CLOCK=10.000000,HLS_INPUT_ARCH=others,HLS_SYN_CLOCK=2.783000,HLS_SYN_LAT=41,HLS_SYN_TPT=none,HLS_SYN_MEM=0,HLS_SYN_DSP=0,HLS_SYN_FF=25,HLS_SYN_LUT=139,HLS_VERSION=2019_1}" *)

module m_add (
        ap_clk,
        ap_rst,
        ap_start,
        ap_done,
        ap_idle,
        ap_ready,
        A_address0,
        A_ce0,
        A_q0,
        B_address0,
        B_ce0,
        B_q0,
        result_address0,
        result_ce0,
        result_we0,
        result_d0
);

parameter    ap_ST_fsm_state1 = 4'd1;
parameter    ap_ST_fsm_state2 = 4'd2;
parameter    ap_ST_fsm_state3 = 4'd4;
parameter    ap_ST_fsm_state4 = 4'd8;

input   ap_clk;
input   ap_rst;
input   ap_start;
output   ap_done;
output   ap_idle;
output   ap_ready;
output  [3:0] A_address0;
output   A_ce0;
input  [31:0] A_q0;
output  [3:0] B_address0;
output   B_ce0;
input  [31:0] B_q0;
output  [3:0] result_address0;
output   result_ce0;
output   result_we0;
output  [31:0] result_d0;

reg ap_done;
reg ap_idle;
reg ap_ready;
reg A_ce0;
reg B_ce0;
reg result_ce0;
reg result_we0;

(* fsm_encoding = "none" *) reg   [3:0] ap_CS_fsm;
wire    ap_CS_fsm_state1;
wire   [2:0] i_fu_95_p2;
reg   [2:0] i_reg_150;
wire    ap_CS_fsm_state2;
wire   [5:0] zext_ln9_fu_109_p1;
reg   [5:0] zext_ln9_reg_155;
wire   [0:0] icmp_ln8_fu_89_p2;
wire   [2:0] j_fu_119_p2;
reg   [2:0] j_reg_163;
wire    ap_CS_fsm_state3;
wire   [63:0] zext_ln10_1_fu_134_p1;
reg   [63:0] zext_ln10_1_reg_168;
wire   [0:0] icmp_ln9_fu_113_p2;
reg   [2:0] i_0_reg_67;
reg   [2:0] j_0_reg_78;
wire    ap_CS_fsm_state4;
wire   [4:0] tmp_fu_101_p3;
wire   [5:0] zext_ln10_fu_125_p1;
wire   [5:0] add_ln10_1_fu_129_p2;
reg   [3:0] ap_NS_fsm;

// power-on initialization
initial begin
#0 ap_CS_fsm = 4'd1;
end

always @ (posedge ap_clk) begin
    if (ap_rst == 1'b1) begin
        ap_CS_fsm <= ap_ST_fsm_state1;
    end else begin
        ap_CS_fsm <= ap_NS_fsm;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln9_fu_113_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state3))) begin
        i_0_reg_67 <= i_reg_150;
    end else if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
        i_0_reg_67 <= 3'd0;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln8_fu_89_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        j_0_reg_78 <= 3'd0;
    end else if ((1'b1 == ap_CS_fsm_state4)) begin
        j_0_reg_78 <= j_reg_163;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state2)) begin
        i_reg_150 <= i_fu_95_p2;
    end
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        j_reg_163 <= j_fu_119_p2;
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln9_fu_113_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state3))) begin
        zext_ln10_1_reg_168[5 : 0] <= zext_ln10_1_fu_134_p1[5 : 0];
    end
end

always @ (posedge ap_clk) begin
    if (((icmp_ln8_fu_89_p2 == 1'd0) & (1'b1 == ap_CS_fsm_state2))) begin
        zext_ln9_reg_155[4 : 2] <= zext_ln9_fu_109_p1[4 : 2];
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        A_ce0 = 1'b1;
    end else begin
        A_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state3)) begin
        B_ce0 = 1'b1;
    end else begin
        B_ce0 = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln8_fu_89_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_done = 1'b1;
    end else begin
        ap_done = 1'b0;
    end
end

always @ (*) begin
    if (((ap_start == 1'b0) & (1'b1 == ap_CS_fsm_state1))) begin
        ap_idle = 1'b1;
    end else begin
        ap_idle = 1'b0;
    end
end

always @ (*) begin
    if (((icmp_ln8_fu_89_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
        ap_ready = 1'b1;
    end else begin
        ap_ready = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        result_ce0 = 1'b1;
    end else begin
        result_ce0 = 1'b0;
    end
end

always @ (*) begin
    if ((1'b1 == ap_CS_fsm_state4)) begin
        result_we0 = 1'b1;
    end else begin
        result_we0 = 1'b0;
    end
end

always @ (*) begin
    case (ap_CS_fsm)
        ap_ST_fsm_state1 : begin
            if (((ap_start == 1'b1) & (1'b1 == ap_CS_fsm_state1))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end
        end
        ap_ST_fsm_state2 : begin
            if (((icmp_ln8_fu_89_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state2))) begin
                ap_NS_fsm = ap_ST_fsm_state1;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state3;
            end
        end
        ap_ST_fsm_state3 : begin
            if (((icmp_ln9_fu_113_p2 == 1'd1) & (1'b1 == ap_CS_fsm_state3))) begin
                ap_NS_fsm = ap_ST_fsm_state2;
            end else begin
                ap_NS_fsm = ap_ST_fsm_state4;
            end
        end
        ap_ST_fsm_state4 : begin
            ap_NS_fsm = ap_ST_fsm_state3;
        end
        default : begin
            ap_NS_fsm = 'bx;
        end
    endcase
end

assign A_address0 = zext_ln10_1_fu_134_p1;

assign B_address0 = zext_ln10_1_fu_134_p1;

assign add_ln10_1_fu_129_p2 = (zext_ln9_reg_155 + zext_ln10_fu_125_p1);

assign ap_CS_fsm_state1 = ap_CS_fsm[32'd0];

assign ap_CS_fsm_state2 = ap_CS_fsm[32'd1];

assign ap_CS_fsm_state3 = ap_CS_fsm[32'd2];

assign ap_CS_fsm_state4 = ap_CS_fsm[32'd3];

assign i_fu_95_p2 = (i_0_reg_67 + 3'd1);

assign icmp_ln8_fu_89_p2 = ((i_0_reg_67 == 3'd4) ? 1'b1 : 1'b0);

assign icmp_ln9_fu_113_p2 = ((j_0_reg_78 == 3'd4) ? 1'b1 : 1'b0);

assign j_fu_119_p2 = (j_0_reg_78 + 3'd1);

assign result_address0 = zext_ln10_1_reg_168;

assign result_d0 = (B_q0 + A_q0);

assign tmp_fu_101_p3 = {{i_0_reg_67}, {2'd0}};

assign zext_ln10_1_fu_134_p1 = add_ln10_1_fu_129_p2;

assign zext_ln10_fu_125_p1 = j_0_reg_78;

assign zext_ln9_fu_109_p1 = tmp_fu_101_p3;

always @ (posedge ap_clk) begin
    zext_ln9_reg_155[1:0] <= 2'b00;
    zext_ln9_reg_155[5] <= 1'b0;
    zext_ln10_1_reg_168[63:6] <= 58'b0000000000000000000000000000000000000000000000000000000000;
end

endmodule //m_add
