// 600cac50  FUN_600cac50  size=70 bytes
// --- callers ---
//   600cad24 timers__600cad24
//   600cacb8 timers__600cacb8
// --- callees ---
//   600c9de4 queue__600c9de4
//   6013d360 thunk_EXT_FUN_00007d64
//   6013d060 thunk_EXT_FUN_0000b2e8
//   600c9fb4 FUN_600c9fb4
//   6013d000 thunk_EXT_FUN_00007dac


void FUN_600cac50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  piVar1 = DAT_600cac98;
  thunk_EXT_FUN_00007d64();
  uVar3 = DAT_600caca0;
  uVar2 = DAT_600cac9c;
  if (*piVar1 == 0) {
    thunk_EXT_FUN_0000b2e8(DAT_600cac9c);
    thunk_EXT_FUN_0000b2e8(uVar3);
    uVar4 = DAT_600caca8;
    *DAT_600caca4 = uVar2;
    *DAT_600cacac = uVar3;
    iVar5 = queue__600c9de4(0x1e,0x10,uVar4,DAT_600cacb0,0,param_2,param_3);
    *piVar1 = iVar5;
    if (iVar5 != 0) {
      FUN_600c9fb4(iVar5,DAT_600cacb4);
    }
  }
  thunk_EXT_FUN_00007dac();
  return;
}


