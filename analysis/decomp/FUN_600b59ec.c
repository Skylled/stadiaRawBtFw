// 600b59ec  FUN_600b59ec  size=450 bytes
// --- callers ---
//   600f7f30 FUN_600f7f30
//   6009c7fc FUN_6009c7fc
// --- callees ---
//   600b0e2c FUN_600b0e2c
//   600aa340 FUN_600aa340
//   6009eb9c FUN_6009eb9c
//   600bb534 FUN_600bb534
//   6009c790 FUN_6009c790
//   6009beb0 FUN_6009beb0
//   6009f93c FUN_6009f93c
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600f1746 FUN_600f1746
//   6009f644 FUN_6009f644


undefined4 FUN_600b59ec(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  undefined1 local_31;
  undefined1 auStack_30 [8];
  undefined2 local_28;
  undefined2 local_26;
  int local_24;
  int local_20;
  byte local_19;
  
  local_20 = FUN_600f1746(param_1 + 4);
  local_24 = DAT_600b5bb0;
  local_19 = 0;
  if (local_20 == 0) {
    uVar6 = 0;
  }
  else {
    if (*(short *)(DAT_600b5bb0 + 0xea) == -1) {
      local_26 = 0x60;
    }
    else {
      local_26 = *(undefined2 *)(DAT_600b5bb0 + 0xea);
    }
    if (*(short *)(DAT_600b5bb0 + 0xec) == -1) {
      local_28 = 0x30;
    }
    else {
      local_28 = *(undefined2 *)(DAT_600b5bb0 + 0xec);
    }
    local_31 = *(undefined1 *)(param_1 + 0x33);
    thunk_EXT_FUN_0000b572(auStack_30,param_1 + 4,6);
    local_19 = *(char *)(DAT_600b5bb4 + 0xa6a) != '\0';
    if ((*(byte *)(local_20 + 0x72) & 2) == 0) {
      FUN_6009f644(1,1);
    }
    else {
      if (1 < *(byte *)(DAT_600b5bb4 + 0xa6a)) {
        local_19 = local_19 | 2;
      }
      FUN_6009f93c(1);
      FUN_6009beb0(auStack_30,&local_31);
    }
    iVar2 = FUN_6009eb9c(2);
    if (iVar2 == 0) {
      FUN_600bb534(param_1);
      uVar6 = 0;
    }
    else {
      if (*(short *)(local_20 + 0xe6) == -1) {
        uVar5 = 0x18;
      }
      else {
        uVar5 = *(undefined2 *)(local_20 + 0xe6);
      }
      if (*(short *)(local_20 + 0xe8) == -1) {
        uVar4 = 0x28;
      }
      else {
        uVar4 = *(undefined2 *)(local_20 + 0xe8);
      }
      if (*(short *)(local_20 + 0xea) == -1) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined2 *)(local_20 + 0xea);
      }
      if (*(short *)(local_20 + 0xec) == -1) {
        uVar1 = 700;
      }
      else {
        uVar1 = *(undefined2 *)(local_20 + 0xec);
      }
      iVar2 = FUN_600b0e2c(local_26,local_28,0,local_31,auStack_30,local_19,uVar5,uVar4,uVar3,uVar1,
                           0,0);
      if (iVar2 == 0) {
        FUN_600bb534(param_1);
        uVar6 = 0;
      }
      else {
        *(undefined1 *)(param_1 + 1) = 3;
        *(undefined1 *)(DAT_600b5bb8 + 0xf42) = 1;
        thunk_EXT_FUN_0000b572(DAT_600b5bbc,param_1 + 4,6);
        FUN_600aa340(param_1 + 0x44,2,0x1e);
        FUN_6009c790(1);
        uVar6 = 1;
      }
    }
  }
  return uVar6;
}


