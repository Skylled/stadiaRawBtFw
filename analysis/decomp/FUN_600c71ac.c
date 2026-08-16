// 600c71ac  FUN_600c71ac  size=560 bytes
// --- callers ---
//   600ff888 FUN_600ff888
//   600f2532 FUN_600f2532
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


void FUN_600c71ac(char *param_1,undefined1 param_2)

{
  char local_2c [2];
  short local_2a;
  short local_28;
  short local_26;
  short local_24;
  short local_22;
  short local_20;
  short local_1e;
  short local_1c;
  short local_1a;
  short local_18;
  short local_16;
  short local_14;
  short local_12;
  short local_10;
  short local_e;
  short local_c;
  
  thunk_EXT_FUN_0000b5ba(local_2c,0,0x22);
  local_2c[0] = *param_1;
  if (local_2c[0] == '\0') {
    local_2a = (ushort)(byte)param_1[2] * 0x100 + (ushort)(byte)param_1[1];
    local_28 = (ushort)(byte)param_1[4] * 0x100 + (ushort)(byte)param_1[3];
    local_26 = (ushort)(byte)param_1[6] * 0x100 + (ushort)(byte)param_1[5];
    local_24 = (ushort)(byte)param_1[8] * 0x100 + (ushort)(byte)param_1[7];
    local_22 = (ushort)(byte)param_1[10] * 0x100 + (ushort)(byte)param_1[9];
    local_20 = (ushort)(byte)param_1[0xc] * 0x100 + (ushort)(byte)param_1[0xb];
    local_1e = (ushort)(byte)param_1[0xe] * 0x100 + (ushort)(byte)param_1[0xd];
    local_1c = (ushort)(byte)param_1[0x10] * 0x100 + (ushort)(byte)param_1[0xf];
    local_1a = (ushort)(byte)param_1[0x12] * 0x100 + (ushort)(byte)param_1[0x11];
    local_18 = (ushort)(byte)param_1[0x14] * 0x100 + (ushort)(byte)param_1[0x13];
    local_16 = (ushort)(byte)param_1[0x16] * 0x100 + (ushort)(byte)param_1[0x15];
    local_14 = (ushort)(byte)param_1[0x18] * 0x100 + (ushort)(byte)param_1[0x17];
    local_12 = (ushort)(byte)param_1[0x1a] * 0x100 + (ushort)(byte)param_1[0x19];
    local_10 = (ushort)(byte)param_1[0x1c] * 0x100 + (ushort)(byte)param_1[0x1b];
    local_e = (ushort)(byte)param_1[0x1e] * 0x100 + (ushort)(byte)param_1[0x1d];
    local_c = (ushort)(byte)param_1[0x20] * 0x100 + (ushort)(byte)param_1[0x1f];
  }
  if (*(int *)(DAT_600c73dc + 0x7fc) != 0) {
    (**(code **)(DAT_600c73dc + 0x7fc))(4,param_2,local_2c);
  }
  return;
}


