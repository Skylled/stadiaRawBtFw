// 6009c9d4  FUN_6009c9d4  size=168 bytes
// --- callers ---
//   600fd308 FUN_600fd308
// --- callees ---
//   6009c444 FUN_6009c444
//   6009c59c FUN_6009c59c


char FUN_6009c9d4(char param_1,undefined4 param_2)

{
  undefined1 local_9;
  
  local_9 = '\x01';
  if ((*(byte *)(DAT_6009ca7c + 0x81b) & 2) == 0) {
    local_9 = '\0';
  }
  else if (param_1 != *(char *)(DAT_6009ca7c + 0x9b8)) {
    if (param_1 == '\x01') {
      FUN_6009c444(1);
    }
    else if (param_1 == '\x02') {
      if (*(char *)(DAT_6009ca7c + 0x9b8) == '\x01') {
        FUN_6009c444(0);
      }
      FUN_6009c59c(1,param_2);
    }
    else if (param_1 == '\0') {
      if (*(char *)(DAT_6009ca7c + 0x9b8) == '\x01') {
        FUN_6009c444(0);
      }
      else if (*(char *)(DAT_6009ca7c + 0x9b8) == '\x02') {
        FUN_6009c59c(0,0);
      }
      local_9 = '\x01';
    }
    else {
      local_9 = '\0';
    }
    if (local_9 != '\0') {
      *(char *)(DAT_6009ca7c + 0x9b8) = param_1;
    }
  }
  return local_9;
}


