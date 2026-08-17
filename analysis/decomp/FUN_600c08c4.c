// 600c08c4  FUN_600c08c4  size=104 bytes
// --- callers ---
//   600c0930 FUN_600c0930
// --- callees ---
//   600fc9fc FUN_600fc9fc
//   600fbc50 FUN_600fbc50


void FUN_600c08c4(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  
  if (((*(ushort *)(DAT_600c092c + 1) & 0xf) == 0) && (*(short *)(DAT_600c092c + 1) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    FUN_600fc9fc(*DAT_600c092c,param_1);
  }
  else {
    FUN_600fbc50(*DAT_600c092c,(byte)*(undefined2 *)(DAT_600c092c + 1) & 0xf);
    FUN_600fc9fc(*DAT_600c092c,param_2);
  }
  return;
}


