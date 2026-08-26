// 600d4724  FUN_600d4724  size=46 bytes
// --- callers ---
//   600cbdc8 xbara__600cbdc8
// --- callees ---
//   6013d2d8 thunk_EXT_FUN_00001c18
//   600ce8be FUN_600ce8be
//   6013d178 thunk_EXT_FUN_00008996
//   600ce8de FUN_600ce8de
//   600522b8 FUN_600522b8
//   601017e8 FUN_601017e8


void FUN_600d4724(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  uStack_14 = param_2;
  uStack_10 = param_3;
  uStack_c = param_4;
  FUN_601017e8(param_1 + 4);
  FUN_600ce8be(&uStack_14);
  uVar1 = thunk_EXT_FUN_00001c18(*param_1);
  FUN_600522b8(uVar1,&uStack_14);
  thunk_EXT_FUN_00001c18(*param_1);
  FUN_600ce8de();
  thunk_EXT_FUN_00008996();
  return;
}


