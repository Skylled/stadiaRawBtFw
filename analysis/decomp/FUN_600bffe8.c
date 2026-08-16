// 600bffe8  FUN_600bffe8  size=256 bytes
// --- callers ---
//   600faec4 FUN_600faec4
//   600fab3e FUN_600fab3e
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600c0c84 FUN_600c0c84
//   600c1a34 FUN_600c1a34


void FUN_600bffe8(int param_1,undefined4 param_2)

{
  undefined1 local_1c [4];
  int local_18;
  undefined1 local_11;
  undefined1 *local_10;
  char local_9;
  
  local_11 = 0x10;
  local_9 = '\0';
  local_10 = (undefined1 *)0x0;
  switch(*(undefined1 *)(param_1 + 0x194)) {
  case 0:
    if (((*(char *)(param_1 + 0x26) == '\0') && ((*(byte *)(param_1 + 0x191) & 4) != 0)) &&
       ((*(byte *)(param_1 + 0x192) & 4) == 0)) {
      local_11 = 3;
      local_10 = &local_11;
      local_9 = '\x17';
    }
    else {
      *(undefined1 *)(param_1 + 0x2b) = 1;
      local_1c[0] = 0;
      local_18 = param_1 + 0x1b6;
      local_10 = local_1c;
      thunk_EXT_FUN_0000b5ba(param_1 + 0x1b6,0,0x10);
      local_9 = '\x10';
    }
    break;
  case 1:
    *(undefined1 *)(param_1 + 0x2b) = 4;
    *(undefined1 *)(param_1 + 0x2a) = 4;
    local_9 = '\x16';
    break;
  case 2:
    *(undefined1 *)(param_1 + 0x2b) = 4;
    *(undefined1 *)(param_1 + 0x2a) = 5;
    local_9 = '\x16';
    break;
  case 3:
    *(undefined1 *)(param_1 + 0x2b) = 4;
    FUN_600c0c84(param_1,0,4,param_1,param_2);
    break;
  case 4:
  case 5:
  case 6:
  case 7:
  case 8:
    local_9 = '\x1b';
    break;
  case 9:
    local_10 = &local_11;
    local_9 = '\x17';
    break;
  default:
    local_10 = &local_11;
    local_9 = '\x17';
  }
  if (local_9 != '\0') {
    FUN_600c1a34(param_1,local_9,local_10);
  }
  return;
}


