// 600cb428  key_value_store__600cb428  size=46 bytes
// src: key_value_store.cc
// --- callers ---
//   60101198 FUN_60101198
// --- callees ---
//   60100f90 FUN_60100f90
//   6010165c FUN_6010165c


/* src: key_value_store.cc */

void key_value_store__600cb428(undefined4 param_1)

{
  char cVar1;
  
  FUN_6010165c(0x14,DAT_600cb45c,0x180,DAT_600cb458);
  cVar1 = FUN_60100f90(param_1,1,0);
  if (cVar1 == '\0') {
    FUN_60100f90(param_1,0);
    return;
  }
  return;
}


