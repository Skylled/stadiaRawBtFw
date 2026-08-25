// 600f58c8  FUN_600f58c8  size=102 bytes
// --- callers ---
//   600f5b32 FUN_600f5b32
// --- callees ---
//   600b50d0 FUN_600b50d0
//   600f6132 FUN_600f6132
//   600f610e FUN_600f610e
//   600f768a FUN_600f768a


undefined1 FUN_600f58c8(undefined4 param_1,int param_2,char param_3)

{
  undefined2 uVar1;
  int iVar2;
  undefined1 local_9;
  
  local_9 = 0;
  iVar2 = FUN_600f6132(param_2);
  if (iVar2 != 4) {
    FUN_600f610e(param_2,2);
  }
  if (param_3 == '\x02') {
    *(undefined2 *)(param_2 + 0x18) = 4;
    local_9 = FUN_600b50d0(4,param_1);
  }
  else {
    uVar1 = FUN_600f768a(0x1f,param_1);
    *(undefined2 *)(param_2 + 0x18) = uVar1;
    if (*(short *)(param_2 + 0x18) != 0) {
      local_9 = 1;
    }
  }
  return local_9;
}


