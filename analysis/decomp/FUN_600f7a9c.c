// 600f7a9c  FUN_600f7a9c  size=138 bytes
// --- callers ---
//   600f3bde FUN_600f3bde
// --- callees ---
//   600fa0d6 FUN_600fa0d6
//   600bb6dc FUN_600bb6dc


undefined4 FUN_600f7a9c(undefined4 param_1,ushort param_2,undefined2 param_3)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined1 local_9;
  
  local_9 = 1;
  if ((3 < param_2) && (param_2 < 7)) {
    local_9 = 2;
  }
  pcVar1 = (char *)FUN_600bb6dc(param_1,local_9);
  if (((pcVar1 == (char *)0x0) || (7 < param_2)) || (*(int *)(pcVar1 + (param_2 + 0x20) * 4) == 0))
  {
    uVar2 = 0;
  }
  else {
    *(undefined2 *)(*(int *)(pcVar1 + (param_2 + 0x20) * 4) + 0x120) = param_3;
    if (((*pcVar1 != '\0') && (pcVar1[1] == '\x04')) && (*(int *)(pcVar1 + 0x5c) == 0)) {
      FUN_600fa0d6(pcVar1);
    }
    uVar2 = 1;
  }
  return uVar2;
}


