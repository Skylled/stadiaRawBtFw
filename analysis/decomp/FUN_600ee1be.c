// 600ee1be  FUN_600ee1be  size=64 bytes
// --- callers ---
//   600928ac FUN_600928ac
// --- callees ---
//   600eff9c FUN_600eff9c
//   60098668 FUN_60098668


undefined1 FUN_600ee1be(char *param_1)

{
  if (*param_1 == '\x01') {
    FUN_60098668(param_1[1]);
  }
  else {
    if (*param_1 != '\x02') {
      return 0;
    }
    FUN_600eff9c(param_1[1]);
  }
  return 1;
}


