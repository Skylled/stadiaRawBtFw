// 600f735a  FUN_600f735a  size=334 bytes
// --- callers ---
//   600f74a8 FUN_600f74a8
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f139a FUN_600f139a
//   600b0548 FUN_600b0548
//   6009ca80 FUN_6009ca80


undefined1 FUN_600f735a(int param_1,undefined4 param_2,char param_3)

{
  char cVar1;
  char *pcVar2;
  undefined1 local_b;
  byte local_a;
  byte local_9;
  
  cVar1 = *(char *)(param_1 + 0x2c);
  local_b = 0;
  pcVar2 = (char *)FUN_600b0548(param_2);
  if (pcVar2 == (char *)0x0) {
    return 0;
  }
  local_9 = 0;
  do {
    if ((9 < local_9) || ((pcVar2[local_9] == '\0' && (pcVar2[local_9 + 10] == '\0'))))
    goto LAB_600f747e;
    local_a = local_9;
    if (param_3 == '\0') {
      if (cVar1 == pcVar2[local_9 + 10]) {
        pcVar2[local_9 + 10] = '\0';
        *(char *)(param_1 + 0x2e) = *(char *)(param_1 + 0x2e) + -1;
        while (local_a = local_a + 1, local_a < 10) {
          pcVar2[local_a + 9] = pcVar2[local_a + 10];
        }
        if (pcVar2[10] == '\0') {
          local_b = FUN_600f139a(0,pcVar2 + 0x14);
        }
        else {
          local_b = 1;
        }
        goto LAB_600f747e;
      }
    }
    else if (cVar1 == pcVar2[local_9]) {
      pcVar2[local_9] = '\0';
      while (local_a = local_a + 1, local_a < 10) {
        pcVar2[local_a - 1] = pcVar2[local_a];
      }
      if (*pcVar2 == '\0') {
        local_b = FUN_6009ca80(0,pcVar2 + 0x14);
      }
      else {
        local_b = 1;
      }
LAB_600f747e:
      if (local_9 == 10) {
        return local_b;
      }
      if (*pcVar2 != '\0') {
        return local_b;
      }
      if (pcVar2[10] != '\0') {
        return local_b;
      }
      thunk_EXT_FUN_0000b5ba(pcVar2,0,0x1b);
      return local_b;
    }
    local_9 = local_9 + 1;
  } while( true );
}


