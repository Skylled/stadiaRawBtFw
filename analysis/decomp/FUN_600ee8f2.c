// 600ee8f2  FUN_600ee8f2  size=136 bytes
// --- callers ---
//   600ee97a FUN_600ee97a
//   600ee9c6 FUN_600ee9c6
//   600ee89c FUN_600ee89c
//   600ee99c FUN_600ee99c
// --- callees ---
//   600f39fc FUN_600f39fc
//   600ee82a FUN_600ee82a
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4 FUN_600ee8f2(undefined2 param_1,undefined4 param_2,char param_3)

{
  undefined4 uVar1;
  undefined1 auStack_24 [20];
  ushort local_10;
  ushort local_e [2];
  undefined1 local_9;
  
  local_9 = 1;
  thunk_EXT_FUN_0000b5ba(auStack_24,0,0x18);
  if ((param_3 == '\x01') || (param_3 == '\x02')) {
    local_10 = 1;
    local_e[0] = 0xffff;
  }
  else {
    if (param_3 == '\x05') {
      local_9 = 0;
    }
    FUN_600ee82a(param_2,&local_10,local_e,local_9);
    if (local_e[0] < local_10) {
      return 0x85;
    }
  }
  uVar1 = FUN_600f39fc(param_1,param_3,auStack_24);
  return uVar1;
}


