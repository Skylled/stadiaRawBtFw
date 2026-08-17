// 600a3f40  FUN_600a3f40  size=114 bytes
// --- callers ---
//   600c269c FUN_600c269c
// --- callees ---
//   6009bb3c FUN_6009bb3c
//   600c0558 FUN_600c0558
//   6013d168 thunk_EXT_FUN_0000b554


undefined4 FUN_600a3f40(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  if (((*(byte *)(DAT_600a3fb4 + 0x81b) & 2) != 0) && (param_1[8] != 0)) {
    FUN_600c0558(DAT_600a3fb8);
    iVar1 = thunk_EXT_FUN_0000b554(DAT_600a3fbc,&local_20,0x10);
    if (iVar1 == 0) {
      FUN_6009bb3c();
    }
  }
  iVar1 = DAT_600a3fb4;
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  *(undefined4 *)(DAT_600a3fb4 + 0x1118) = *param_1;
  *(undefined4 *)(iVar1 + 0x111c) = uVar2;
  *(undefined4 *)(iVar1 + 0x1120) = uVar3;
  *(undefined4 *)(iVar1 + 0x1124) = uVar4;
  uVar2 = param_1[5];
  uVar3 = param_1[6];
  uVar4 = param_1[7];
  *(undefined4 *)(iVar1 + 0x1128) = param_1[4];
  *(undefined4 *)(iVar1 + 0x112c) = uVar2;
  *(undefined4 *)(iVar1 + 0x1130) = uVar3;
  *(undefined4 *)(iVar1 + 0x1134) = uVar4;
  uVar2 = param_1[9];
  *(undefined4 *)(iVar1 + 0x1138) = param_1[8];
  *(undefined4 *)(iVar1 + 0x113c) = uVar2;
  return 1;
}


