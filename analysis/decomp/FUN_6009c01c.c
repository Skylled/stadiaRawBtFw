// 6009c01c  FUN_6009c01c  size=102 bytes
// --- callers ---
//   6009c59c FUN_6009c59c
//   6009e84c FUN_6009e84c
//   6009c444 FUN_6009c444
// --- callees ---
//   600f1148 FUN_600f1148
//   6013cf90 thunk_EXT_FUN_0000b5ba


char FUN_6009c01c(void)

{
  char local_e;
  byte local_d;
  char *local_c;
  
  local_e = '\x01';
  local_d = 0;
  for (local_c = DAT_6009c084; ((local_d < 10 && (local_e != '\0')) && (*local_c != '\0'));
      local_c = local_c + 9) {
    local_e = FUN_600f1148(local_c[1],local_c + 2,local_c[8]);
    thunk_EXT_FUN_0000b5ba(local_c,0,9);
    local_d = local_d + 1;
  }
  return local_e;
}


