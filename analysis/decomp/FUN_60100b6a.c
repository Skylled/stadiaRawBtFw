// 60100b6a  FUN_60100b6a  size=44 bytes
// --- callers ---
//   60100ed8 FUN_60100ed8
//   60100ffc FUN_60100ffc
//   600cb6fc key_value_store__600cb6fc
//   60100c48 FUN_60100c48
//   60101198 FUN_60101198
// --- callees ---
//   60100b24 FUN_60100b24


short FUN_60100b6a(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  undefined4 extraout_r2;
  
  uVar1 = *(undefined1 *)(param_1 + 0x59);
  sVar2 = FUN_60100b24(uVar1,8);
  sVar3 = FUN_60100b24(uVar1,param_2);
  sVar4 = FUN_60100b24(uVar1,extraout_r2);
  return sVar4 + sVar2 + sVar3;
}


