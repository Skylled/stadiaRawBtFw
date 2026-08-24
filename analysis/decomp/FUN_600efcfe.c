// 600efcfe  FUN_600efcfe  size=68 bytes
// --- callers ---
//   6006c594 FUN_6006c594
//   6009362c FUN_6009362c
//   600ef5be FUN_600ef5be
//   600c424c FUN_600c424c
//   60093a30 FUN_60093a30
//   600936d4 FUN_600936d4
//   60094ffc FUN_60094ffc
//   600951ec FUN_600951ec
//   600d9176 FUN_600d9176
//   600c5574 FUN_600c5574
//   600ef648 FUN_600ef648
//   600c5670 FUN_600c5670
//   600c2b3c FUN_600c2b3c
//   600c4da8 FUN_600c4da8
//   60093d20 FUN_60093d20
//   600944c0 FUN_600944c0
//   600952fc FUN_600952fc
//   600c5ef4 FUN_600c5ef4
//   6009547c FUN_6009547c
//   60093810 FUN_60093810
//   60095588 FUN_60095588
//   600c0434 FUN_600c0434
//   6009519c FUN_6009519c
// --- callees ---


undefined4 FUN_600efcfe(char *param_1,char *param_2)

{
  char *local_18;
  char *local_14;
  int local_c;
  
  local_c = 6;
  local_18 = param_2;
  local_14 = param_1;
  while( true ) {
    if (local_c == 0) {
      return 0;
    }
    if (*local_14 != *local_18) break;
    local_c = local_c + -1;
    local_18 = local_18 + 1;
    local_14 = local_14 + 1;
  }
  return 0xffffffff;
}


