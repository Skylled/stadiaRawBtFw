// 600f4cf4  FUN_600f4cf4  size=108 bytes
// --- callers ---
//   600acf50 FUN_600acf50
// --- callees ---
//   600f80c4 FUN_600f80c4
//   600b00b4 FUN_600b00b4


void FUN_600f4cf4(int param_1,int param_2,undefined4 param_3,byte *param_4)

{
  ushort uVar1;
  
  uVar1 = (ushort)param_4[1] * 0x100 + (ushort)*param_4;
  if ((uVar1 < *(ushort *)(param_1 + 0x1a)) && (0x16 < uVar1)) {
    *(ushort *)(param_1 + 0x1a) = uVar1;
  }
  FUN_600f80c4(param_1 + 0xd,4,*(undefined2 *)(param_1 + 0x1a),*(undefined2 *)(param_1 + 0x1a),
               param_4 + 2);
  FUN_600b00b4(param_2,*(undefined1 *)(param_2 + 0x33),0);
  return;
}


