// 600d4c3a  FUN_600d4c3a  size=116 bytes
// --- callers ---
//   600656a0 haptics__600656a0
// --- callees ---
//   600600c4 pwm__600600c4
//   600cf548 FUN_600cf548
//   6006012c pwm__6006012c
//   6013cef0 thunk_EXT_FUN_0000887a
//   6013d3d8 thunk_EXT_FUN_0000b4c2
//   600600f8 pwm__600600f8


undefined4 FUN_600d4c3a(char *param_1,undefined1 param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  char *local_1c [2];
  
  if (((param_1[10] == '\0') || (*param_1 == '\0')) || (param_1[1] == '\0')) {
    uVar4 = 9;
  }
  else {
    local_1c[0] = param_1 + 0x68;
    thunk_EXT_FUN_0000b4c2();
    uVar4 = pwm__6006012c(*(undefined4 *)(param_1 + 4));
    uVar2 = pwm__600600c4(param_1[8]);
    FUN_600cf548(uVar4,uVar2,1,3,param_2);
    iVar3 = pwm__6006012c(*(undefined4 *)(param_1 + 4));
    uVar4 = 0;
    uVar1 = pwm__600600f8(param_1[8]);
    *(ushort *)(iVar3 + 0x188) = uVar1 & 0xf | *(ushort *)(iVar3 + 0x188);
    thunk_EXT_FUN_0000887a(local_1c);
  }
  return uVar4;
}


