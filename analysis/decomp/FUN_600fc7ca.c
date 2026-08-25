// 600fc7ca  FUN_600fc7ca  size=166 bytes
// --- callers ---
// --- callees ---
//   600fcd40 FUN_600fcd40
//   600fcd08 FUN_600fcd08
//   600fc870 FUN_600fc870
//   600c1a34 FUN_600c1a34
//   600fcd96 FUN_600fcd96


void FUN_600fc7ca(int param_1,undefined4 param_2)

{
  undefined1 local_3d;
  undefined1 local_3c [4];
  undefined1 *local_38;
  undefined1 auStack_34 [16];
  undefined1 auStack_24 [8];
  undefined1 auStack_1c [8];
  undefined1 auStack_14 [3];
  char local_11;
  
  local_3d = 8;
  FUN_600fcd08(auStack_14,param_1);
  FUN_600fcd40(auStack_1c,param_1);
  FUN_600fcd96(auStack_24,param_1);
  local_11 = FUN_600fc870(param_1 + 0x1a0,param_1 + 0x4d,param_1 + 0x5d,param_1 + 0xcd,auStack_14,
                          auStack_24,auStack_1c,auStack_34,param_2);
  if (local_11 == '\0') {
    FUN_600c1a34(param_1,0x17,&local_3d);
  }
  else {
    local_3c[0] = 3;
    local_38 = auStack_34;
    FUN_600c1a34(param_1,0x25,local_3c);
  }
  return;
}


