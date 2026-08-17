// 6009feb8  FUN_6009feb8  size=90 bytes
// --- callers ---
//   600a730c FUN_600a730c
//   600f033a FUN_600f033a
//   600a67ec FUN_600a67ec
//   600a6aa4 FUN_600a6aa4
//   600a6720 FUN_600a6720
//   600a7268 FUN_600a7268
//   60098f88 FUN_60098f88
//   6009af60 FUN_6009af60
//   600a6b20 FUN_600a6b20
//   600f1e24 FUN_600f1e24
// --- callees ---


int FUN_6009feb8(short param_1)

{
  int local_10;
  int local_c;
  
  local_c = DAT_6009ff14;
  local_10 = 0;
  do {
    if (7 < local_10) {
      return 0;
    }
    if ((*(ushort *)(local_c + 0x2a) & 0x80) != 0) {
      if (param_1 == *(short *)(local_c + 0xc)) {
        return local_c;
      }
      if (param_1 == *(short *)(local_c + 0x5e)) {
        return local_c;
      }
    }
    local_10 = local_10 + 1;
    local_c = local_c + 0xfc;
  } while( true );
}


