// 600af074  FUN_600af074  size=58 bytes
// --- callers ---
//   600af0b4 FUN_600af0b4
// --- callees ---
//   600aefc0 FUN_600aefc0
//   600af020 FUN_600af020


bool FUN_600af074(undefined4 param_1,short param_2)

{
  undefined1 local_9;
  
  local_9 = param_2 == *(short *)(DAT_600af0b0 + 0x1550);
  if (local_9) {
    FUN_600aefc0(param_1);
  }
  local_9 = !local_9;
  FUN_600af020(param_1);
  return local_9;
}


