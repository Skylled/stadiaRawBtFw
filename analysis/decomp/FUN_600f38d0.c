// 600f38d0  FUN_600f38d0  size=124 bytes
// --- callers ---
//   600ff1f6 FUN_600ff1f6
//   600f3f70 FUN_600f3f70
// --- callees ---
//   600f622a FUN_600f622a
//   600af7c8 FUN_600af7c8
//   600afd28 FUN_600afd28


undefined1 FUN_600f38d0(undefined2 param_1,int param_2,undefined1 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = FUN_600afd28((char)param_1);
  iVar3 = FUN_600af7c8((char)((ushort)param_1 >> 8));
  if ((iVar2 == 0) || (iVar3 == 0)) {
    uVar1 = 0xff;
  }
  else if (param_2 == *(int *)(iVar3 + 0x2c)) {
    uVar1 = FUN_600f622a(iVar3,(char)param_1,param_2,*(undefined1 *)(iVar3 + 0x56),param_3,param_4);
  }
  else {
    uVar1 = 0x82;
  }
  return uVar1;
}


