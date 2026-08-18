// 600af718  FUN_600af718  size=64 bytes
// --- callers ---
//   600aefc0 FUN_600aefc0
//   600f5fb4 FUN_600f5fb4
//   600f5bfc FUN_600f5bfc
//   600f6042 FUN_600f6042
//   600f5ede FUN_600f5ede
// --- callees ---
//   600d92f8 FUN_600d92f8
//   6013d168 thunk_EXT_FUN_0000b554
//   600d92fc FUN_600d92fc


int FUN_600af718(undefined4 param_1)

{
  int iVar1;
  int local_c;
  
  local_c = FUN_600d92f8(DAT_600af758);
  while ((local_c != 0 && (iVar1 = thunk_EXT_FUN_0000b554(param_1,local_c,6), iVar1 != 0))) {
    local_c = FUN_600d92fc(local_c);
  }
  return local_c;
}


