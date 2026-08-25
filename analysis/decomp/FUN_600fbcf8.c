// 600fbcf8  FUN_600fbcf8  size=84 bytes
// --- callers ---
//   600c09f0 FUN_600c09f0
// --- callees ---
//   600c0930 FUN_600c0930
//   600fbc02 FUN_600fbc02


undefined1 FUN_600fbcf8(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_30 [20];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_9;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_9 = 1;
  iVar1 = FUN_600fbc02(param_1,0x10,&local_1c,0x10,auStack_30);
  if (iVar1 == 0) {
    local_9 = 0;
  }
  else {
    FUN_600c0930(auStack_30);
  }
  return local_9;
}


