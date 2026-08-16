// 600696d0  adapter__600696d0  size=160 bytes
// src: adapter.cc
// --- callers ---
//   60081c6c FUN_60081c6c
// --- callees ---
//   600d3b3a FUN_600d3b3a
//   60101822 FUN_60101822
//   6010165c FUN_6010165c
//   600d37ac FUN_600d37ac
//   600d8994 FUN_600d8994
//   60101740 FUN_60101740
//   600d890c FUN_600d890c
//   600955dc FUN_600955dc


/* src: adapter.cc */

undefined4
adapter__600696d0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  undefined *local_b8;
  undefined4 local_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined2 local_8;
  
  iVar1 = FUN_600d8994(param_1 + 0x110);
  if (iVar1 == 0) {
    uVar2 = 9;
  }
  else {
    if (param_2 == 0) {
      local_b8 = (undefined *)CONCAT22(local_b8._2_2_,2);
      local_8 = (undefined2)param_3;
      local_b4 = CONCAT22(local_b4._2_2_,local_8);
    }
    else {
      if (param_2 != 1) {
        local_b8 = PTR_s_adapter_cc_60069778;
        local_b4 = 0x254;
        FUN_600d3b3a(&uStack_b0);
        FUN_600d37ac(&uStack_b0,PTR_s_CHECK_failed_60122ce9_9_6006977c);
        FUN_60101740(&local_b8);
      }
      local_b8 = (undefined *)CONCAT22(local_b8._2_2_,0x10);
      uStack_ac = param_5;
      uStack_a8 = param_6;
      local_b4 = param_3;
      uStack_b0 = param_4;
    }
    FUN_600955dc(&local_b8,PTR_LAB_60069dc8_1_60069770);
    iVar1 = FUN_60101822(param_1 + 0x1e78,5000);
    if (iVar1 == 0) {
      FUN_6010165c(0x28,PTR_s_adapter_cc_60069778,0x25b,
                   PTR_s_Timeout_while_waiting_for_applic_60069774);
      uVar2 = 4;
    }
    else {
      uVar2 = FUN_600d890c(param_1);
    }
  }
  return uVar2;
}


