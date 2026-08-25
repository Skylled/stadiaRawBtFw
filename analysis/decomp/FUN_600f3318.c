// 600f3318  FUN_600f3318  size=96 bytes
// --- callers ---
// --- callees ---
//   600f322e FUN_600f322e
//   600aa800 FUN_600aa800
//   600aa6f0 FUN_600aa6f0
//   600f32aa FUN_600f32aa


void FUN_600f3318(undefined4 param_1,undefined4 param_2,undefined2 param_3,char param_4)

{
  int iVar1;
  
  iVar1 = FUN_600aa6f0(param_2);
  if (iVar1 != 0) {
    if (param_4 == '\0') {
      *(undefined1 *)(iVar1 + 0x11) = 0;
      FUN_600f32aa(iVar1,0,0,0);
      FUN_600aa800(iVar1);
    }
    else {
      *(undefined2 *)(iVar1 + 0xc) = param_3;
      *(undefined1 *)(iVar1 + 0x11) = 1;
      FUN_600f322e(iVar1);
    }
  }
  return;
}


