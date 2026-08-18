// 600d10b8  FUN_600d10b8  size=62 bytes
// --- callers ---
//   600548c4 FUN_600548c4
//   600547ac FUN_600547ac
//   60054728 FUN_60054728
//   60054f30 FUN_60054f30
//   60055224 FUN_60055224
// --- callees ---
//   600d0ede FUN_600d0ede


undefined4 FUN_600d10b8(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    uVar2 = 3;
  }
  else {
    if ((param_2 != 0) && (param_3 != (undefined4 *)0x0)) {
      uVar3 = *(byte *)(param_2 + 2) & 0xf;
      if (uVar3 < 8) {
        uVar2 = *param_3;
        iVar1 = ((uint)(*(byte *)(param_2 + 2) >> 7) | uVar3 << 1) * 0xc + param_1;
        *(undefined4 *)(iVar1 + 0x10) = param_3[1];
        *(undefined4 *)(iVar1 + 0xc) = uVar2;
        *(undefined1 *)(iVar1 + 0x14) = 0;
        uVar2 = FUN_600d0ede(param_1,2,param_2);
        return uVar2;
      }
    }
    uVar2 = 4;
  }
  return uVar2;
}


