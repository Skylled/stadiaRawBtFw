// 600f592e  FUN_600f592e  size=148 bytes
// --- callers ---
//   600f6afc FUN_600f6afc
//   600f3da6 FUN_600f3da6
//   600f7052 FUN_600f7052
//   600ab9b8 FUN_600ab9b8
// --- callees ---
//   600b54d4 FUN_600b54d4
//   600f6132 FUN_600f6132
//   600f7a34 FUN_600f7a34
//   600f610e FUN_600f610e
//   600b542c FUN_600b542c


undefined1 FUN_600f592e(int param_1)

{
  char cVar1;
  undefined1 local_9;
  
  local_9 = 0;
  if (param_1 != 0) {
    local_9 = 1;
    cVar1 = FUN_600f6132(param_1);
    if ((cVar1 != '\x01') && (cVar1 != '\0')) {
      if (*(short *)(param_1 + 0x18) == 4) {
        if (cVar1 == '\x04') {
          local_9 = FUN_600b542c(4,param_1 + 0xd);
        }
        else {
          cVar1 = FUN_600b54d4(param_1 + 0xd);
          if (cVar1 == '\x01') {
            FUN_600f610e(param_1,1);
            local_9 = 1;
          }
          else {
            local_9 = FUN_600b542c(4,param_1 + 0xd);
          }
        }
      }
      else {
        local_9 = FUN_600f7a34(*(undefined2 *)(param_1 + 0x18));
      }
    }
  }
  return local_9;
}


