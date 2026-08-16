// 600a1fc8  FUN_600a1fc8  size=430 bytes
// --- callers ---
//   600c2f68 FUN_600c2f68
// --- callees ---
//   600a01a0 FUN_600a01a0
//   600a27fc FUN_600a27fc
//   6009dd74 FUN_6009dd74


char FUN_600a1fc8(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char local_9;
  
  iVar2 = DAT_600a2178;
  local_9 = '\x01';
  if ((*(char *)(DAT_600a2178 + 0x61e) == '\0') && (*(char *)(DAT_600a2178 + 0x61a) == '\0')) {
    iVar3 = FUN_600a01a0();
    if (iVar3 == 0) {
      local_9 = '\x06';
    }
    else if (((((*param_1 & 3) == 1) || ((*param_1 & 3) == 2)) || ((*param_1 & 0x30) == 0x10)) ||
            ((*param_1 & 0x30) == 0x20)) {
      uVar4 = *(undefined4 *)(param_1 + 4);
      *(undefined4 *)(iVar2 + 0x608) = *(undefined4 *)param_1;
      *(undefined4 *)(iVar2 + 0x60c) = uVar4;
      bVar1 = param_1[10];
      *(undefined2 *)(iVar2 + 0x610) = *(undefined2 *)(param_1 + 8);
      *(byte *)(iVar2 + 0x612) = bVar1;
      *(undefined1 *)(iVar2 + 0x61d) = 3;
      *(undefined4 *)(iVar2 + 0x34) = param_3;
      *(undefined4 *)(iVar2 + 0x38) = param_2;
      *(undefined1 *)(iVar2 + 0x614) = 0;
      *(byte *)(iVar2 + 0x61e) = *param_1;
      if ((*param_1 & 0x30) != 0) {
        if ((*(byte *)(DAT_600a217c + 0x81b) & 2) == 0) {
          *(byte *)(iVar2 + 0x608) = *(byte *)(iVar2 + 0x608) & 0xcf;
          local_9 = '\x05';
        }
        else {
          local_9 = FUN_6009dd74(*param_1 & 0x30,param_1[1],param_1[4],param_1 + 5);
          if (local_9 != '\x01') {
            *(byte *)(iVar2 + 0x608) = *(byte *)(iVar2 + 0x608) & 0xcf;
          }
        }
        *param_1 = *param_1 & 0xcf;
      }
      if ((*param_1 & 3) == 0) {
        if (local_9 != '\x01') {
          *(undefined1 *)(iVar2 + 0x61e) = 0;
          *(undefined4 *)(iVar2 + 0x38) = 0;
          *(undefined4 *)(iVar2 + 0x34) = 0;
        }
      }
      else {
        if (param_1[4] == 0) {
          *(undefined1 *)(iVar2 + 0x61d) = 2;
        }
        else {
          if (2 < param_1[4]) {
            *(undefined1 *)(iVar2 + 0x61e) = 0;
            return '\x05';
          }
          *(undefined1 *)(iVar2 + 0x61d) = 1;
          param_1[4] = 0;
        }
        local_9 = FUN_600a27fc(param_1[4],param_1 + 5);
        if (local_9 != '\x01') {
          *(undefined1 *)(iVar2 + 0x61d) = 0;
        }
      }
    }
    else {
      local_9 = '\x05';
    }
  }
  else {
    local_9 = '\x02';
  }
  return local_9;
}


