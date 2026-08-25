// 600fcab6  FUN_600fcab6  size=124 bytes
// --- callers ---
//   600fb968 FUN_600fb968
//   600fb93a FUN_600fb93a
//   600fb988 FUN_600fb988
// --- callees ---
//   600fca7c FUN_600fca7c
//   6013d3a0 thunk_EXT_FUN_0000b572


void FUN_600fcab6(undefined4 *param_1)

{
  ushort uVar1;
  undefined1 auStack_1c [8];
  undefined4 local_14;
  undefined4 local_10;
  code *local_c;
  
  local_10 = 0;
  local_c = (code *)*param_1;
  uVar1 = (ushort)*(byte *)((int)param_1 + 0x25);
  if (*(char *)((int)param_1 + 0x25) == '\0') {
    local_14._0_2_ = CONCAT11(*(undefined1 *)((int)param_1 + 0x2b),*(byte *)((int)param_1 + 0x25));
    uVar1 = (ushort)local_14;
  }
  local_14._0_3_ = (uint3)uVar1;
  if (*(char *)((int)param_1 + 0x1fa) != '\0') {
    local_14._0_3_ = CONCAT12(1,uVar1);
  }
  local_14 = (uint)(uint3)local_14;
  thunk_EXT_FUN_0000b572(auStack_1c,(int)param_1 + 0x1d,6);
  FUN_600fca7c(param_1);
  if (local_c != (code *)0x0) {
    (*local_c)(7,auStack_1c,&local_14);
  }
  return;
}


