// 600d55b8  FUN_600d55b8  size=38 bytes
// --- callers ---
//   60062ba4 usb_host_audio__60062ba4
// --- callees ---
//   600d5592 FUN_600d5592


void FUN_600d55b8(int param_1)

{
  undefined2 uVar1;
  
  *(short *)(param_1 + 4) =
       (short)((((int)*(short *)(param_1 + 0xc) - (int)*(short *)(param_1 + 8)) * 100) /
              (int)(short)(*(short *)(param_1 + 10) - *(short *)(param_1 + 8)));
  uVar1 = FUN_600d5592();
  *(undefined2 *)(param_1 + 0xc) = uVar1;
  return;
}


