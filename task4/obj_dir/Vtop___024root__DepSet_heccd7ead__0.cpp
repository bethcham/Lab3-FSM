// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__top__DOT__LFSR__DOT__sreg = vlSelf->top__DOT__LFSR__DOT__sreg;
    if (vlSelf->rst) {
        vlSelf->__Vdly__top__DOT__LFSR__DOT__sreg = 1U;
        vlSelf->top__DOT__FSM__DOT__current_state = 0U;
    } else {
        vlSelf->__Vdly__top__DOT__LFSR__DOT__sreg = 
            ((0x7eU & ((IData)(vlSelf->top__DOT__LFSR__DOT__sreg) 
                       << 1U)) | (1U & VL_REDXOR_8(
                                                   (0x44U 
                                                    & (IData)(vlSelf->top__DOT__LFSR__DOT__sreg)))));
        if (vlSelf->trigger) {
            vlSelf->top__DOT__FSM__DOT__current_state = 1U;
        } else if (vlSelf->top__DOT__tick) {
            vlSelf->top__DOT__FSM__DOT__current_state 
                = vlSelf->top__DOT__FSM__DOT__next_state;
        }
    }
    if (((((((((0U == vlSelf->top__DOT__FSM__DOT__current_state) 
               | (1U == vlSelf->top__DOT__FSM__DOT__current_state)) 
              | (2U == vlSelf->top__DOT__FSM__DOT__current_state)) 
             | (3U == vlSelf->top__DOT__FSM__DOT__current_state)) 
            | (4U == vlSelf->top__DOT__FSM__DOT__current_state)) 
           | (5U == vlSelf->top__DOT__FSM__DOT__current_state)) 
          | (6U == vlSelf->top__DOT__FSM__DOT__current_state)) 
         | (7U == vlSelf->top__DOT__FSM__DOT__current_state))) {
        if ((0U == vlSelf->top__DOT__FSM__DOT__current_state)) {
            vlSelf->top__DOT__FSM__DOT__next_state = 1U;
            vlSelf->data_out = 0U;
        } else if ((1U == vlSelf->top__DOT__FSM__DOT__current_state)) {
            vlSelf->top__DOT__FSM__DOT__next_state = 2U;
            vlSelf->data_out = 1U;
        } else if ((2U == vlSelf->top__DOT__FSM__DOT__current_state)) {
            vlSelf->top__DOT__FSM__DOT__next_state = 3U;
            vlSelf->data_out = 3U;
        } else if ((3U == vlSelf->top__DOT__FSM__DOT__current_state)) {
            vlSelf->top__DOT__FSM__DOT__next_state = 4U;
            vlSelf->data_out = 7U;
        } else if ((4U == vlSelf->top__DOT__FSM__DOT__current_state)) {
            vlSelf->top__DOT__FSM__DOT__next_state = 5U;
            vlSelf->data_out = 0xfU;
        } else if ((5U == vlSelf->top__DOT__FSM__DOT__current_state)) {
            vlSelf->top__DOT__FSM__DOT__next_state = 6U;
            vlSelf->data_out = 0x1fU;
        } else if ((6U == vlSelf->top__DOT__FSM__DOT__current_state)) {
            vlSelf->top__DOT__FSM__DOT__next_state = 7U;
            vlSelf->data_out = 0x3fU;
        } else {
            vlSelf->top__DOT__FSM__DOT__next_state = 8U;
            vlSelf->data_out = 0x7fU;
        }
    } else {
        vlSelf->top__DOT__FSM__DOT__next_state = 0U;
        vlSelf->data_out = ((8U == vlSelf->top__DOT__FSM__DOT__current_state)
                             ? 0xffU : 0U);
    }
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__1\n"); );
    // Init
    SData/*15:0*/ __Vdly__top__DOT__clock__DOT__count;
    // Body
    __Vdly__top__DOT__clock__DOT__count = vlSelf->top__DOT__clock__DOT__count;
    if (vlSelf->rst) {
        vlSelf->top__DOT__tick = 0U;
        __Vdly__top__DOT__clock__DOT__count = vlSelf->N;
        vlSelf->top__DOT__DELAY__DOT__current_state = 0U;
    } else {
        if (vlSelf->top__DOT__cmd_seq) {
            if ((0U == (IData)(vlSelf->top__DOT__clock__DOT__count))) {
                vlSelf->top__DOT__tick = 1U;
                __Vdly__top__DOT__clock__DOT__count 
                    = vlSelf->N;
            } else {
                __Vdly__top__DOT__clock__DOT__count 
                    = (0xffffU & ((IData)(vlSelf->top__DOT__clock__DOT__count) 
                                  - (IData)(1U)));
                vlSelf->top__DOT__tick = 0U;
            }
        }
        vlSelf->top__DOT__DELAY__DOT__current_state 
            = vlSelf->top__DOT__DELAY__DOT__next_state;
    }
    vlSelf->top__DOT__DELAY__DOT__count = (0x3ffU & 
                                           ((((IData)(vlSelf->rst) 
                                              | (IData)(vlSelf->top__DOT__cmd_delay)) 
                                             | (0U 
                                                == (IData)(vlSelf->top__DOT__DELAY__DOT__count)))
                                             ? ((IData)(vlSelf->top__DOT__LFSR__DOT__sreg) 
                                                - (IData)(1U))
                                             : ((IData)(vlSelf->top__DOT__DELAY__DOT__count) 
                                                - (IData)(1U))));
    vlSelf->top__DOT__clock__DOT__count = __Vdly__top__DOT__clock__DOT__count;
    vlSelf->time_out = ((0U != vlSelf->top__DOT__DELAY__DOT__current_state) 
                        & ((1U != vlSelf->top__DOT__DELAY__DOT__current_state) 
                           & (2U == vlSelf->top__DOT__DELAY__DOT__current_state)));
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__2\n"); );
    // Body
    vlSelf->top__DOT__cmd_seq = (((((((((0U == vlSelf->top__DOT__FSM__DOT__current_state) 
                                        | (1U == vlSelf->top__DOT__FSM__DOT__current_state)) 
                                       | (2U == vlSelf->top__DOT__FSM__DOT__current_state)) 
                                      | (3U == vlSelf->top__DOT__FSM__DOT__current_state)) 
                                     | (4U == vlSelf->top__DOT__FSM__DOT__current_state)) 
                                    | (5U == vlSelf->top__DOT__FSM__DOT__current_state)) 
                                   | (6U == vlSelf->top__DOT__FSM__DOT__current_state)) 
                                  | (7U == vlSelf->top__DOT__FSM__DOT__current_state))
                                  ? (0U != vlSelf->top__DOT__FSM__DOT__current_state)
                                  : (8U == vlSelf->top__DOT__FSM__DOT__current_state));
    vlSelf->top__DOT__LFSR__DOT__sreg = vlSelf->__Vdly__top__DOT__LFSR__DOT__sreg;
    vlSelf->top__DOT__cmd_delay = ((~ ((((((((0U == vlSelf->top__DOT__FSM__DOT__current_state) 
                                             | (1U 
                                                == vlSelf->top__DOT__FSM__DOT__current_state)) 
                                            | (2U == vlSelf->top__DOT__FSM__DOT__current_state)) 
                                           | (3U == vlSelf->top__DOT__FSM__DOT__current_state)) 
                                          | (4U == vlSelf->top__DOT__FSM__DOT__current_state)) 
                                         | (5U == vlSelf->top__DOT__FSM__DOT__current_state)) 
                                        | (6U == vlSelf->top__DOT__FSM__DOT__current_state)) 
                                       | (7U == vlSelf->top__DOT__FSM__DOT__current_state))) 
                                   & (8U == vlSelf->top__DOT__FSM__DOT__current_state));
    vlSelf->top__DOT__DELAY__DOT__next_state = ((0U 
                                                 == vlSelf->top__DOT__DELAY__DOT__current_state)
                                                 ? 
                                                ((IData)(vlSelf->top__DOT__cmd_delay)
                                                  ? 1U
                                                  : vlSelf->top__DOT__DELAY__DOT__current_state)
                                                 : 
                                                ((1U 
                                                  == vlSelf->top__DOT__DELAY__DOT__current_state)
                                                  ? 
                                                 ((0U 
                                                   == (IData)(vlSelf->top__DOT__DELAY__DOT__count))
                                                   ? 2U
                                                   : vlSelf->top__DOT__DELAY__DOT__current_state)
                                                  : 
                                                 ((2U 
                                                   == vlSelf->top__DOT__DELAY__DOT__current_state)
                                                   ? 
                                                  ((IData)(vlSelf->top__DOT__cmd_delay)
                                                    ? 3U
                                                    : 0U)
                                                   : 
                                                  ((3U 
                                                    == vlSelf->top__DOT__DELAY__DOT__current_state)
                                                    ? 
                                                   ((IData)(vlSelf->top__DOT__cmd_delay)
                                                     ? vlSelf->top__DOT__DELAY__DOT__current_state
                                                     : 0U)
                                                    : 0U))));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtop___024root___sequent__TOP__2(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
}
#endif  // VL_DEBUG
