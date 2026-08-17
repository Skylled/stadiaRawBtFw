// 600a93b0  FUN_600a93b0  size=136 bytes
// --- callers ---
//   600a89f0 FUN_600a89f0
// --- callees ---
//   600a5540 FUN_600a5540
//   600b22a8 FUN_600b22a8


void FUN_600a93b0(char *param_1)

{
  char *pcVar1;
  int iVar2;
  char *local_24;
  undefined1 auStack_1c [2];
  char local_1a [7];
  char local_13 [3];
  
  pcVar1 = local_13;
  local_24 = param_1;
  for (iVar2 = 0; iVar2 < 6; iVar2 = iVar2 + 1) {
    *pcVar1 = *local_24;
    pcVar1 = pcVar1 + -1;
    local_24 = local_24 + 1;
  }
  pcVar1 = local_1a;
  for (iVar2 = 0; iVar2 < 3; iVar2 = iVar2 + 1) {
    *pcVar1 = *local_24;
    pcVar1 = pcVar1 + -1;
    local_24 = local_24 + 1;
  }
  local_13[2] = *local_24;
  if (local_13[2] == '\x01') {
    if (*DAT_600a9438 == '\0') {
      FUN_600a5540(local_1a + 2,auStack_1c);
    }
    else {
      FUN_600b22a8(local_1a + 2,1);
    }
  }
  return;
}


