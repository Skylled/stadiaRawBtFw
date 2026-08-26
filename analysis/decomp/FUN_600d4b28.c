// 600d4b28  FUN_600d4b28  size=80 bytes
// --- callers ---
//   600656a0 haptics__600656a0
// --- callees ---
//   6006012c pwm__6006012c
//   6013cef0 thunk_EXT_FUN_0000887a
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600600f8 pwm__600600f8


undefined4 FUN_600d4b28(char *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  char *local_14;
  
  if ((*param_1 == '\0') || (param_1[1] == '\0')) {
    uVar3 = 9;
  }
  else {
    local_14 = param_1 + 0x68;
    thunk_EXT_FUN_0000b4c2();
    iVar2 = pwm__6006012c(*(undefined4 *)(param_1 + 4));
    uVar3 = 0;
    uVar1 = pwm__600600f8(param_1[8]);
    *(ushort *)(iVar2 + 0x188) = *(ushort *)(iVar2 + 0x188) & ~((uVar1 & 0xf) << 8);
    thunk_EXT_FUN_0000887a(&local_14);
  }
  return uVar3;
}


