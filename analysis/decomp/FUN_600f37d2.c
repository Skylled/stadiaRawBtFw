// 600f37d2  FUN_600f37d2  size=254 bytes
// --- callers ---
//   600ff21c FUN_600ff21c
// --- callees ---
//   600c7eb8 FUN_600c7eb8
//   600af7c8 FUN_600af7c8
//   600ff9fe FUN_600ff9fe
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600afd28 FUN_600afd28


undefined1 FUN_600f37d2(undefined2 param_1,short param_2,undefined2 param_3,undefined4 param_4)

{
  undefined1 auStack_284 [2];
  short local_282;
  undefined2 local_27e;
  undefined1 local_27c;
  undefined1 auStack_27b [603];
  int local_20;
  int local_1c;
  int local_18;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  
  local_11 = 0x87;
  local_12 = (undefined1)param_1;
  local_13 = (undefined1)((ushort)param_1 >> 8);
  local_18 = FUN_600afd28(local_12);
  local_1c = FUN_600af7c8(local_13);
  if ((local_18 == 0) || (local_1c == 0)) {
    local_11 = 0xff;
  }
  else if (param_2 != 0) {
    local_282 = param_2;
    local_27e = param_3;
    thunk_EXT_FUN_0000b572(auStack_27b,param_4,param_3);
    local_27c = 0;
    local_20 = FUN_600c7eb8(local_1c,0x1b,auStack_284);
    if (local_20 == 0) {
      local_11 = 0x80;
    }
    else {
      local_11 = FUN_600ff9fe(local_1c,local_20);
    }
  }
  return local_11;
}


