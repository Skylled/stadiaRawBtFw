// 600c54ec  FUN_600c54ec  size=46 bytes
// --- callers ---
//   600c5908 FUN_600c5908
//   600c5db0 FUN_600c5db0
//   600c3c00 FUN_600c3c00
//   600c5d3c FUN_600c5d3c
//   600c3558 FUN_600c3558
// --- callees ---
//   600f1700 FUN_600f1700


char * FUN_600c54ec(void)

{
  char *pcVar1;
  undefined4 local_c;
  
  local_c = DAT_600c551c;
  if (*DAT_600c551c == '\0') {
    pcVar1 = (char *)FUN_600f1700(DAT_600c5520);
    if (pcVar1 != (char *)0x0) {
      local_c = pcVar1;
    }
  }
  return local_c;
}


