// 600ac2a4  FUN_600ac2a4  size=384 bytes
// --- callers ---
//   600ac438 FUN_600ac438
// --- callees ---
//   600f194c FUN_600f194c
//   600f0a98 FUN_600f0a98
//   600f0b06 FUN_600f0b06


char FUN_600ac2a4(int *param_1)

{
  char local_18;
  byte local_17;
  byte local_16;
  char local_15;
  int local_14;
  char local_d;
  char local_c;
  char local_b;
  char local_a;
  char local_9;
  
  local_9 = '\x01';
  local_14 = *param_1;
  local_15 = (char)param_1[0xc];
  local_a = '\0';
  local_b = '\0';
  local_c = '\0';
  local_d = '\0';
  local_18 = '\0';
  if (local_15 == '\0') {
    local_9 = '\x01';
  }
  else {
    FUN_600f194c(local_14 + 0xd,&local_16,*(undefined1 *)(*param_1 + 0x13));
    FUN_600f0b06(local_14 + 0xd,local_15,&local_18);
    if ((local_18 == '\x03') && (local_15 != '\0')) {
      local_9 = '\x06';
    }
    else {
      if ((local_16 & 0x14) != 0) {
        if ((local_16 & 4) != 0) {
          local_a = '\x01';
        }
        if ((local_16 & 2) != 0) {
          local_d = '\x01';
        }
        if ((local_16 & 0x20) != 0) {
          local_c = '\x01';
        }
        if ((local_16 & 0x10) != 0) {
          local_b = '\x01';
        }
      }
      switch(local_15) {
      case '\x01':
        if (local_a == '\0') {
          local_9 = '\x04';
        }
        break;
      case '\x02':
        if (local_d == '\0') {
          local_9 = '\x05';
        }
        break;
      case '\x03':
        if ((local_a == '\0') && (local_b == '\0')) {
          local_9 = '\x04';
        }
        break;
      case '\x04':
        if ((local_c == '\0') && ((local_a == '\0' || (local_d == '\0')))) {
          local_9 = '\x05';
        }
      }
      if (local_9 == '\x01') {
        if (((*(char *)(local_14 + 0x13) == '\x02') && (*(char *)((int)param_1 + 0x31) == '\x03'))
           && (*(char *)((int)param_1 + 0x32) == '\x01')) {
          if (local_a == '\0') {
            FUN_600f0a98(local_14 + 0xd,&local_17);
            if (((local_17 & 0x40) == 0) || ((local_15 != '\x03' && (local_15 != '\x04')))) {
              local_9 = '\x03';
            }
            else {
              local_9 = '\x02';
            }
          }
        }
        else if (local_a == '\0') {
          local_9 = '\x03';
        }
      }
    }
  }
  return local_9;
}


