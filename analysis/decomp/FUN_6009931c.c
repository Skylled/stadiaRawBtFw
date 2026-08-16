// 6009931c  FUN_6009931c  size=402 bytes
// --- callers ---
//   600bc480 FUN_600bc480
//   600c53f8 FUN_600c53f8
//   600c4d18 FUN_600c4d18
// --- callees ---
//   6009ff18 FUN_6009ff18
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600a3424 FUN_600a3424
//   600a35e4 FUN_600a35e4
//   60098ec8 FUN_60098ec8
//   600b26d0 FUN_600b26d0
//   600b2eec FUN_600b2eec
//   6013cf90 thunk_EXT_FUN_0000b5ba


char FUN_6009931c(undefined4 param_1,char param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_1c [8];
  undefined1 local_14;
  char local_12;
  char local_11;
  undefined2 *local_10;
  int local_c;
  
  local_c = 0;
  if ((*(byte *)(DAT_600994b0 + 0x813) & 0x20) == 0) {
    local_11 = '\x04';
  }
  else if ((*(int *)(DAT_600994b0 + 2000) == 0) || (param_3 == 0)) {
    local_10 = (undefined2 *)FUN_60098ec8(param_1,1);
    if (local_10 == (undefined2 *)0x0) {
      local_11 = '\a';
    }
    else if (param_2 == *(char *)((int)local_10 + 0x129)) {
      local_11 = '\0';
    }
    else if (*(char *)((int)local_10 + 299) == '\0') {
      local_11 = FUN_600a35e4(local_10 + 3,&local_12);
      if (local_11 == '\0') {
        if ((local_12 == '\x03') || (local_12 == '\x02')) {
          thunk_EXT_FUN_0000b5ba(auStack_1c,0,10);
          local_14 = 0;
          cVar1 = FUN_600a3424(0x80,local_10 + 3,auStack_1c);
          if (cVar1 != '\x01') {
            return '\x06';
          }
          *(undefined1 *)((int)local_10 + 299) = 1;
          local_11 = '\x01';
        }
        else {
          local_c = FUN_6009ff18(param_1);
          if (((local_c == 0) || ((*(ushort *)(local_c + 0x2a) & 4) == 0)) ||
             (((*(byte *)((int)local_10 + 0x113) & 4) != 0 &&
              ((*(byte *)(DAT_600994b0 + 0x818) & 4) != 0)))) {
            iVar2 = FUN_600b2eec(param_1,param_2);
            if (iVar2 == 0) {
              return '\x03';
            }
            *(undefined1 *)((int)local_10 + 299) = 5;
            if (local_c != 0) {
              *(undefined1 *)(local_c + 0xee) = 1;
            }
          }
          else {
            if (*(char *)((int)local_10 + 0x12d) != '\x01') {
              iVar2 = FUN_600b26d0(*local_10,0);
              if (iVar2 == 0) {
                return '\x03';
              }
              *(undefined1 *)((int)local_10 + 0x12d) = 1;
            }
            *(undefined1 *)((int)local_10 + 299) = 2;
          }
        }
        if (param_3 != 0) {
          thunk_EXT_FUN_0000b572(DAT_600994b4,param_1,6);
          *(char *)(DAT_600994b0 + 0x7c9) = param_2;
          *(undefined1 *)(DAT_600994b0 + 0x7c8) = 0x11;
          *(int *)(DAT_600994b0 + 2000) = param_3;
        }
        local_11 = '\x01';
      }
    }
    else {
      local_11 = '\x02';
    }
  }
  else {
    local_11 = '\x02';
  }
  return local_11;
}


