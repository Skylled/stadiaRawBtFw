// 600f7f30  FUN_600f7f30  size=68 bytes
// --- callers ---
//   600bc480 FUN_600bc480
// --- callees ---
//   6009c7c8 FUN_6009c7c8
//   600b59ec FUN_600b59ec
//   6009c6d8 FUN_6009c6d8
//   6009c778 FUN_6009c778


undefined1 FUN_600f7f30(undefined4 param_1)

{
  char cVar1;
  undefined1 local_9;
  
  cVar1 = FUN_6009c778();
  if (cVar1 == '\0') {
    local_9 = FUN_600b59ec(param_1);
  }
  else {
    FUN_6009c7c8(param_1);
    if (cVar1 == '\x02') {
      FUN_6009c6d8();
    }
    local_9 = 1;
  }
  return local_9;
}


