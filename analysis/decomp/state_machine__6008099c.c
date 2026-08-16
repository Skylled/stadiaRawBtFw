// 6008099c  state_machine__6008099c  size=200 bytes
// src: state_machine.cc
// --- callers ---
//   6005b8dc application_state__6005b8dc
// --- callees ---
//   601016f0 FUN_601016f0
//   600df2a6 FUN_600df2a6
//   600df264 state_machine__600df264
//   600d37ac FUN_600d37ac
//   600df286 FUN_600df286
//   600df218 FUN_600df218
//   600d3b24 FUN_600d3b24
//   600805e4 state_machine__600805e4


/* src: state_machine.cc */

void state_machine__6008099c(int param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_ac;
  undefined *local_a8;
  undefined4 local_a4;
  byte *local_a0;
  undefined4 local_9c;
  uint uStack_98;
  byte local_94;
  byte local_93;
  byte local_92 [134];
  
  if (*param_2 == 7) {
    *(undefined1 *)(param_1 + 0xe4) = 1;
  }
  local_94 = *(byte *)(param_1 + 0xe4);
  uStack_98 = (uint)local_94;
  if (uStack_98 == 0) {
    local_a8 = PTR_s_state_machine_cc_60080a64;
    local_a4 = 0xb8;
    local_a0 = local_92;
    local_9c = 0x80;
    local_93 = local_94;
    local_92[0] = local_94;
    FUN_600d37ac(&local_a0,PTR_s_Discarding_OOBE_event_60080a68);
    FUN_600df286(&local_a0,param_2);
    FUN_600d37ac(&local_a0,PTR_s_seen_before_startup__60080a6c);
    FUN_601016f0(0x1e,local_a8,local_a4,&local_a0);
  }
  else {
    uVar1 = state_machine__600805e4();
    iVar2 = state_machine__600df264(param_1,uVar1);
    if (iVar2 != 0) {
      local_a8 = PTR_s_state_machine_cc_60080a64;
      local_a4 = 0xbd;
      local_a0 = local_92;
      local_9c = 0x80;
      uStack_98 = 0;
      local_94 = 0;
      local_93 = 0;
      local_92[0] = 0;
      FUN_600d37ac(&local_a0,PTR_s_Transitioned_to_60080a70);
      local_ac = FUN_600df218(param_1);
      FUN_600df2a6(&local_a0,&local_ac);
      FUN_600d37ac(&local_a0,PTR_s_after_60080a74);
      FUN_600df286(&local_a0,param_2);
      FUN_600d3b24(&local_a8);
    }
  }
  return;
}


