// 600b643a  FUN_600b643a  size=76 bytes
// --- callers ---
//   60134420 FUN_60134420
// --- callees ---
//   600f8de8 FUN_600f8de8
//   600aa340 FUN_600aa340


void FUN_600b643a(void)

{
  int in_r3;
  int unaff_r7;
  
  if (in_r3 == 0) {
    FUN_600aa340(*(int *)(unaff_r7 + 0xc) + 0x13c,3,0x3c);
    (**(code **)(*(int *)(*(int *)(unaff_r7 + 0xc) + 0x154) + 8))
              (*(int *)(*(int *)(unaff_r7 + 0xc) + 300) + 4,**(undefined2 **)(unaff_r7 + 0xc),
               *(undefined2 *)(*(int *)(*(int *)(unaff_r7 + 0xc) + 0x154) + 2),
               *(undefined1 *)(*(int *)(unaff_r7 + 0xc) + 8));
  }
  else {
    FUN_600f8de8(*(undefined4 *)(unaff_r7 + 0xc),1,0);
  }
  return;
}


