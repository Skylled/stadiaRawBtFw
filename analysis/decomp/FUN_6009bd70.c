// 6009bd70  FUN_6009bd70  size=112 bytes
// --- callers ---
//   6009e3f0 FUN_6009e3f0
//   6009b368 FUN_6009b368
// --- callees ---
//   6009bcd8 FUN_6009bcd8
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_6009bd70(undefined4 param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_6009bde0;
  if (*(char *)(DAT_6009bde0 + 0xd) == '\0') {
    *(undefined4 *)(DAT_6009bde0 + 0x18) = param_3;
    *(undefined1 *)(iVar1 + 0xd) = 1;
    *(undefined2 *)(iVar1 + 0xe) = 0;
    *(code **)(iVar1 + 0x10) = param_2;
    thunk_EXT_FUN_0000b572(iVar1 + 7,param_1,6);
    while (iVar2 = FUN_6009bcd8(*(undefined2 *)(iVar1 + 0xe)), iVar2 == 0) {
      *(short *)(iVar1 + 0xe) = *(short *)(iVar1 + 0xe) + 1;
    }
  }
  else {
    (*param_2)(0,param_3);
  }
  return;
}


