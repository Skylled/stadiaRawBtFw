// 600f43c0  FUN_600f43c0  size=486 bytes
// --- callers ---
//   600ac9a4 FUN_600ac9a4
//   600acddc FUN_600acddc
//   600f4266 FUN_600f4266
// --- callees ---
//   600ffada FUN_600ffada
//   600b00b4 FUN_600b00b4
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600f43c0(undefined4 *param_1,undefined2 param_2)

{
  byte bVar1;
  undefined2 local_274;
  undefined2 local_272;
  undefined2 local_270;
  undefined2 local_26c [2];
  undefined2 local_268;
  undefined4 local_10;
  char local_a;
  char local_9;
  
  local_10 = *param_1;
  local_9 = -0x7f;
  local_a = '\0';
  thunk_EXT_FUN_0000b5ba(&local_274,0,0x264);
  bVar1 = *(byte *)((int)param_1 + 0x32);
  if (bVar1 == 4) {
LAB_600f4426:
    local_a = '\b';
    local_272 = *(undefined2 *)(param_1 + 10);
    local_270 = *(undefined2 *)((int)param_1 + 0x2a);
    if (*(char *)((int)param_1 + 0x32) == '\x01') {
      thunk_EXT_FUN_0000b572(local_26c,param_1 + 4,0x14);
    }
    else {
      local_26c[0] = 2;
      local_268 = 0x2803;
    }
  }
  else {
    if (bVar1 < 5) {
      if (bVar1 != 2) {
        if (2 < bVar1) {
          local_a = '\x0e';
          thunk_EXT_FUN_0000b572(&local_274,param_1[3],0x18);
          goto LAB_600f4552;
        }
        if (bVar1 != 1) goto LAB_600f4552;
        goto LAB_600f4426;
      }
    }
    else if (bVar1 != 0x84) {
      if (bVar1 == 0x93) {
        local_a = '\n';
        local_274 = *(undefined2 *)(param_1 + 10);
        *(byte *)((int)param_1 + 0x32) = *(byte *)((int)param_1 + 0x32) & 0x6f;
      }
      else if (bVar1 == 5) {
        local_a = '\f';
        local_272 = *(undefined2 *)(param_1 + 10);
        local_270 = param_2;
      }
      goto LAB_600f4552;
    }
    if (*(short *)(param_1 + 0xb) == 0) {
      local_a = '\n';
      local_274 = *(undefined2 *)(param_1 + 10);
    }
    else {
      if (*(char *)(param_1 + 0xd) == '\0') {
        *(undefined1 *)(param_1 + 0xd) = 1;
      }
      else {
        *(undefined1 *)(param_1 + 0xd) = 0;
      }
      local_a = '\f';
      local_272 = *(undefined2 *)(param_1 + 10);
      local_270 = param_2;
    }
    *(byte *)((int)param_1 + 0x32) = *(byte *)((int)param_1 + 0x32) & 0x7f;
  }
LAB_600f4552:
  if (local_a != '\0') {
    local_9 = FUN_600ffada(local_10,*(undefined2 *)((int)param_1 + 0x26),local_a,&local_274);
  }
  if ((local_a == '\0') || ((local_9 != '\0' && (local_9 != -0x7a)))) {
    FUN_600b00b4(param_1,local_9,0);
  }
  return;
}


