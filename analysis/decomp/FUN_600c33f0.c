// 600c33f0  FUN_600c33f0  size=80 bytes
// --- callers ---
//   600c3f04 FUN_600c3f04
// --- callees ---
//   600efcc6 FUN_600efcc6
//   600a3fc0 FUN_600a3fc0
//   600f1800 FUN_600f1800


undefined4 FUN_600c33f0(undefined4 param_1,undefined1 param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  FUN_600efcc6(DAT_600c3440,param_1);
  *(undefined1 *)(DAT_600c3444 + 0x21) = 0;
  cVar1 = FUN_600f1800(DAT_600c3440,DAT_600c3448,param_2);
  if (cVar1 == '\x01') {
    uVar2 = 1;
  }
  else if (cVar1 == '\x02') {
    FUN_600a3fc0(DAT_600c344c);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


