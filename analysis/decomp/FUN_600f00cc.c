// 600f00cc  FUN_600f00cc  size=256 bytes
// --- callers ---
//   60098d8c FUN_60098d8c
// --- callees ---
//   600b8f0c FUN_600b8f0c
//   600a1394 FUN_600a1394
//   600bb6dc FUN_600bb6dc


undefined4 FUN_600f00cc(int param_1)

{
  undefined4 uVar1;
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  char local_15;
  char acStack_14 [3];
  char local_11;
  char *local_10;
  int local_c;
  
  local_c = FUN_600bb6dc(param_1,1);
  if (local_c == 0) {
    uVar1 = 0;
  }
  else if ((*(char *)(param_1 + 8) == '\x01') || (*(char *)(param_1 + 8) == '\x02')) {
    local_18 = (undefined1)*(undefined2 *)(local_c + 2);
    local_17 = (undefined1)((ushort)*(undefined2 *)(local_c + 2) >> 8);
    local_10 = &local_15;
    local_16 = *(undefined1 *)(param_1 + 6);
    if (((*(char *)(param_1 + 7) == '\0') && (*(char *)(param_1 + 6) != *(char *)(local_c + 0x28)))
       || ((*(char *)(param_1 + 7) != '\0' && (*(char *)(local_c + 0x28) == '\x01')))) {
      if (*(char *)(param_1 + 8) == '\x01') {
        FUN_600a1394(0xfc57,3,&local_18,0);
      }
      else {
        local_11 = *(char *)(param_1 + 8) + -1;
        local_10 = acStack_14;
        local_15 = local_11;
        FUN_600a1394(0xfd1a,4,&local_18,0);
      }
    }
    *(undefined1 *)(local_c + 0x29) = *(undefined1 *)(param_1 + 8);
    if (*(char *)(local_c + 0x28) != *(char *)(param_1 + 6)) {
      *(undefined1 *)(local_c + 0x28) = *(undefined1 *)(param_1 + 6);
    }
    if (*(char *)(param_1 + 8) != '\x02') {
      FUN_600b8f0c();
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


