// 600f5b32  FUN_600f5b32  size=202 bytes
// --- callers ---
//   600f3c42 FUN_600f3c42
// --- callees ---
//   600af814 FUN_600af814
//   600f6132 FUN_600f6132
//   600af8ac FUN_600af8ac
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f58c8 FUN_600f58c8
//   600f6dc6 FUN_600f6dc6
//   600f5a98 FUN_600f5a98


char FUN_600f5b32(int param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  int iVar2;
  undefined4 local_10;
  undefined1 local_9;
  
  local_9 = '\0';
  local_10 = FUN_600af814(param_2,param_3);
  if (local_10 == 0) {
    local_10 = FUN_600af8ac(param_2,param_3);
    if (local_10 == 0) {
      local_9 = '\0';
    }
    else {
      iVar2 = FUN_600f58c8(param_2,local_10,param_3);
      if (iVar2 == 0) {
        thunk_EXT_FUN_0000b5ba(local_10,0,0x10c);
      }
      else {
        local_9 = '\x01';
      }
    }
  }
  else {
    local_9 = '\x01';
    cVar1 = FUN_600f6132(local_10);
    if (((cVar1 == '\x04') && (iVar2 = FUN_600f6dc6(local_10), iVar2 == 0)) && (param_3 == '\x02'))
    {
      iVar2 = FUN_600f58c8(param_2,local_10,2);
      if (iVar2 == 0) {
        local_9 = '\0';
      }
    }
    else if (cVar1 == '\x01') {
      local_9 = '\0';
    }
  }
  if (local_9 != '\0') {
    FUN_600f5a98(*(undefined1 *)(param_1 + 0x2c),local_10,1,0);
  }
  return local_9;
}


