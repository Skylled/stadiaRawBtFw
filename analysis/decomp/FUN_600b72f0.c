// 600b72f0  FUN_600b72f0  size=38 bytes
// --- callers ---
//   60131a30 FUN_60131a30
// --- callees ---


ushort FUN_600b72f0(undefined4 param_1,uint param_2,ushort param_3,byte *param_4)

{
  ushort uVar1;
  int unaff_r5;
  byte *unaff_r6;
  
  while( true ) {
    uVar1 = *(ushort *)(DAT_600b7318 + (*param_4 ^ param_2) * 2) ^ param_3;
    if (unaff_r5 == 0) break;
    param_3 = uVar1 >> 8;
    param_2 = (uint)(byte)uVar1;
    param_4 = unaff_r6;
    unaff_r5 = unaff_r5 + -1;
    unaff_r6 = unaff_r6 + 1;
  }
  return uVar1;
}


