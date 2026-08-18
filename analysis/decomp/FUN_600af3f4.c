// 600af3f4  FUN_600af3f4  size=76 bytes
// --- callers ---
//   600ab424 FUN_600ab424
//   600f35ae FUN_600f35ae
//   600f3620 FUN_600f3620
//   600f3540 FUN_600f3540
// --- callees ---


undefined4 * FUN_600af3f4(short param_1)

{
  undefined4 *local_c;
  
  local_c = (undefined4 *)*DAT_600af440;
  while( true ) {
    if (local_c == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if ((*(char *)(local_c + 0x15) != '\0') && (param_1 == *(short *)((int)local_c + 0x32))) break;
    local_c = (undefined4 *)*local_c;
  }
  return local_c;
}


