// 600f367e  FUN_600f367e  size=340 bytes
// --- callers ---
//   600af020 FUN_600af020
//   600adad8 FUN_600adad8
//   600ff21c FUN_600ff21c
// --- callees ---
//   600c7eb8 FUN_600c7eb8
//   600af2d0 FUN_600af2d0
//   600f6ab0 FUN_600f6ab0
//   600af7c8 FUN_600af7c8
//   600ff9fe FUN_600ff9fe
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600afd28 FUN_600afd28


char FUN_600f367e(undefined2 param_1,short param_2,undefined2 param_3,undefined4 param_4)

{
  int iVar1;
  undefined2 local_284;
  short local_282;
  undefined2 local_27e;
  undefined1 local_27c;
  undefined1 auStack_27b [603];
  int local_20;
  int local_1c;
  int local_18;
  undefined1 local_13;
  undefined1 local_12;
  char local_11;
  
  local_11 = -0x80;
  local_12 = (undefined1)param_1;
  local_13 = (undefined1)((ushort)param_1 >> 8);
  local_18 = FUN_600afd28(local_12);
  local_1c = FUN_600af7c8(local_13);
  if ((local_18 == 0) || (local_1c == 0)) {
    local_11 = -1;
  }
  else if (param_2 == 0) {
    local_11 = -0x79;
  }
  else {
    local_284 = param_1;
    local_282 = param_2;
    local_27e = param_3;
    thunk_EXT_FUN_0000b572(auStack_27b,param_4,param_3);
    local_27c = 0;
    if (*(short *)(local_1c + 100) == 0) {
      local_20 = FUN_600c7eb8(local_1c,0x1d,&local_284);
      if ((local_20 != 0) &&
         ((local_11 = FUN_600ff9fe(local_1c,local_20), local_11 == '\0' || (local_11 == -0x71)))) {
        *(short *)(local_1c + 100) = local_282;
        FUN_600f6ab0(local_1c);
      }
    }
    else {
      iVar1 = FUN_600af2d0(local_1c,&local_284);
      if (iVar1 != 0) {
        local_11 = '\0';
      }
    }
  }
  return local_11;
}


