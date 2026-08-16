// 600b00b4  FUN_600b00b4  size=550 bytes
// --- callers ---
//   600ac014 FUN_600ac014
//   600f4cb6 FUN_600f4cb6
//   600acf50 FUN_600acf50
//   600acddc FUN_600acddc
//   600b02e0 FUN_600b02e0
//   600f47a0 FUN_600f47a0
//   600ac6ac FUN_600ac6ac
//   600f4d8e FUN_600f4d8e
//   600ac524 FUN_600ac524
//   600f46b4 FUN_600f46b4
//   600f4cf4 FUN_600f4cf4
//   600f45a6 FUN_600f45a6
//   600f4a3c FUN_600f4a3c
//   600ac9a4 FUN_600ac9a4
//   600f4266 FUN_600f4266
//   600f4b8e FUN_600f4b8e
//   600f43c0 FUN_600f43c0
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600f6d9c FUN_600f6d9c
//   6013d3a0 thunk_EXT_FUN_0000b572
//   6006ddd8 FUN_6006ddd8


void FUN_600b00b4(int *param_1,undefined1 param_2,int param_3)

{
  undefined2 local_284;
  undefined2 local_282;
  undefined2 local_27e;
  undefined1 auStack_27b [603];
  undefined2 local_20;
  undefined1 local_1d;
  code *local_1c;
  code *local_18;
  char local_12;
  undefined1 local_11;
  
  local_12 = *(char *)((int)param_1 + 0x31);
  local_11 = 6;
  if (param_1[1] == 0) {
    local_18 = (code *)0x0;
  }
  else {
    local_18 = *(code **)(param_1[1] + 0x18);
  }
  if (param_1[1] == 0) {
    local_1c = (code *)0x0;
  }
  else {
    local_1c = *(code **)(param_1[1] + 0x20);
  }
  thunk_EXT_FUN_0000b5ba(&local_284,0,0x262);
  if ((local_18 != (code *)0x0) && (*(char *)((int)param_1 + 0x31) != '\0')) {
    if (*(char *)((int)param_1 + 0x31) == '\x02') {
      local_282 = (undefined2)param_1[10];
      local_27e = (undefined2)param_1[0xb];
      if ((param_3 != 0) && ((short)param_1[0xb] != 0)) {
        thunk_EXT_FUN_0000b572(auStack_27b,param_3,local_27e);
      }
    }
    if (*(char *)((int)param_1 + 0x31) == '\x03') {
      thunk_EXT_FUN_0000b5ba(&local_284,0,0x262);
      local_284 = (undefined2)param_1[10];
      local_282 = local_284;
      if ((*(char *)((int)param_1 + 0x32) == '\x03') && (param_3 != 0)) {
        thunk_EXT_FUN_0000b572(&local_284,param_3,0x262);
      }
    }
    if (*(char *)((int)param_1 + 0x31) == '\x05') {
      local_284 = *(undefined2 *)(*param_1 + 0x1a);
    }
    if (*(char *)((int)param_1 + 0x31) == '\x01') {
      local_11 = *(undefined1 *)((int)param_1 + 0x32);
    }
  }
  if (param_1[3] != 0) {
    FUN_6006ddd8(param_1[3],DAT_600b02dc,0x85e);
  }
  local_1d = *(undefined1 *)((int)param_1 + 0x31);
  local_20 = (undefined2)param_1[9];
  FUN_600f6d9c(param_1);
  if ((local_1c == (code *)0x0) || (local_12 != '\x01')) {
    if ((local_18 != (code *)0x0) && (local_12 != '\0')) {
      (*local_18)(local_20,local_12,param_2,&local_284);
    }
  }
  else {
    (*local_1c)(local_20,local_11,param_2);
  }
  return;
}


