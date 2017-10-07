#ifndef _ROS_keyboard_Key_h
#define _ROS_keyboard_Key_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace keyboard
{

  class Key : public ros::Msg
  {
    public:
      std_msgs::Header header;
      uint16_t code;
      uint16_t modifiers;
      enum { KEY_UNKNOWN = 0 };
      enum { KEY_FIRST = 0 };
      enum { KEY_BACKSPACE = 8 };
      enum { KEY_TAB = 9 };
      enum { KEY_CLEAR = 12 };
      enum { KEY_RETURN = 13 };
      enum { KEY_PAUSE = 19 };
      enum { KEY_ESCAPE = 27 };
      enum { KEY_SPACE = 32 };
      enum { KEY_EXCLAIM = 33 };
      enum { KEY_QUOTEDBL = 34 };
      enum { KEY_HASH = 35 };
      enum { KEY_DOLLAR = 36 };
      enum { KEY_AMPERSAND = 38 };
      enum { KEY_QUOTE = 39 };
      enum { KEY_LEFTPAREN = 40 };
      enum { KEY_RIGHTPAREN = 41 };
      enum { KEY_ASTERISK = 42 };
      enum { KEY_PLUS = 43 };
      enum { KEY_COMMA = 44 };
      enum { KEY_MINUS = 45 };
      enum { KEY_PERIOD = 46 };
      enum { KEY_SLASH = 47 };
      enum { KEY_0 = 48 };
      enum { KEY_1 = 49 };
      enum { KEY_2 = 50 };
      enum { KEY_3 = 51 };
      enum { KEY_4 = 52 };
      enum { KEY_5 = 53 };
      enum { KEY_6 = 54 };
      enum { KEY_7 = 55 };
      enum { KEY_8 = 56 };
      enum { KEY_9 = 57 };
      enum { KEY_COLON = 58 };
      enum { KEY_SEMICOLON = 59 };
      enum { KEY_LESS = 60 };
      enum { KEY_EQUALS = 61 };
      enum { KEY_GREATER = 62 };
      enum { KEY_QUESTION = 63 };
      enum { KEY_AT = 64 };
      enum { KEY_LEFTBRACKET = 91 };
      enum { KEY_BACKSLASH = 92 };
      enum { KEY_RIGHTBRACKET = 93 };
      enum { KEY_CARET = 94 };
      enum { KEY_UNDERSCORE = 95 };
      enum { KEY_BACKQUOTE = 96 };
      enum { KEY_a = 97 };
      enum { KEY_b = 98 };
      enum { KEY_c = 99 };
      enum { KEY_d = 100 };
      enum { KEY_e = 101 };
      enum { KEY_f = 102 };
      enum { KEY_g = 103 };
      enum { KEY_h = 104 };
      enum { KEY_i = 105 };
      enum { KEY_j = 106 };
      enum { KEY_k = 107 };
      enum { KEY_l = 108 };
      enum { KEY_m = 109 };
      enum { KEY_n = 110 };
      enum { KEY_o = 111 };
      enum { KEY_p = 112 };
      enum { KEY_q = 113 };
      enum { KEY_r = 114 };
      enum { KEY_s = 115 };
      enum { KEY_t = 116 };
      enum { KEY_u = 117 };
      enum { KEY_v = 118 };
      enum { KEY_w = 119 };
      enum { KEY_x = 120 };
      enum { KEY_y = 121 };
      enum { KEY_z = 122 };
      enum { KEY_DELETE = 127 };
      enum { KEY_WORLD_0 = 160 };
      enum { KEY_WORLD_1 = 161 };
      enum { KEY_WORLD_2 = 162 };
      enum { KEY_WORLD_3 = 163 };
      enum { KEY_WORLD_4 = 164 };
      enum { KEY_WORLD_5 = 165 };
      enum { KEY_WORLD_6 = 166 };
      enum { KEY_WORLD_7 = 167 };
      enum { KEY_WORLD_8 = 168 };
      enum { KEY_WORLD_9 = 169 };
      enum { KEY_WORLD_10 = 170 };
      enum { KEY_WORLD_11 = 171 };
      enum { KEY_WORLD_12 = 172 };
      enum { KEY_WORLD_13 = 173 };
      enum { KEY_WORLD_14 = 174 };
      enum { KEY_WORLD_15 = 175 };
      enum { KEY_WORLD_16 = 176 };
      enum { KEY_WORLD_17 = 177 };
      enum { KEY_WORLD_18 = 178 };
      enum { KEY_WORLD_19 = 179 };
      enum { KEY_WORLD_20 = 180 };
      enum { KEY_WORLD_21 = 181 };
      enum { KEY_WORLD_22 = 182 };
      enum { KEY_WORLD_23 = 183 };
      enum { KEY_WORLD_24 = 184 };
      enum { KEY_WORLD_25 = 185 };
      enum { KEY_WORLD_26 = 186 };
      enum { KEY_WORLD_27 = 187 };
      enum { KEY_WORLD_28 = 188 };
      enum { KEY_WORLD_29 = 189 };
      enum { KEY_WORLD_30 = 190 };
      enum { KEY_WORLD_31 = 191 };
      enum { KEY_WORLD_32 = 192 };
      enum { KEY_WORLD_33 = 193 };
      enum { KEY_WORLD_34 = 194 };
      enum { KEY_WORLD_35 = 195 };
      enum { KEY_WORLD_36 = 196 };
      enum { KEY_WORLD_37 = 197 };
      enum { KEY_WORLD_38 = 198 };
      enum { KEY_WORLD_39 = 199 };
      enum { KEY_WORLD_40 = 200 };
      enum { KEY_WORLD_41 = 201 };
      enum { KEY_WORLD_42 = 202 };
      enum { KEY_WORLD_43 = 203 };
      enum { KEY_WORLD_44 = 204 };
      enum { KEY_WORLD_45 = 205 };
      enum { KEY_WORLD_46 = 206 };
      enum { KEY_WORLD_47 = 207 };
      enum { KEY_WORLD_48 = 208 };
      enum { KEY_WORLD_49 = 209 };
      enum { KEY_WORLD_50 = 210 };
      enum { KEY_WORLD_51 = 211 };
      enum { KEY_WORLD_52 = 212 };
      enum { KEY_WORLD_53 = 213 };
      enum { KEY_WORLD_54 = 214 };
      enum { KEY_WORLD_55 = 215 };
      enum { KEY_WORLD_56 = 216 };
      enum { KEY_WORLD_57 = 217 };
      enum { KEY_WORLD_58 = 218 };
      enum { KEY_WORLD_59 = 219 };
      enum { KEY_WORLD_60 = 220 };
      enum { KEY_WORLD_61 = 221 };
      enum { KEY_WORLD_62 = 222 };
      enum { KEY_WORLD_63 = 223 };
      enum { KEY_WORLD_64 = 224 };
      enum { KEY_WORLD_65 = 225 };
      enum { KEY_WORLD_66 = 226 };
      enum { KEY_WORLD_67 = 227 };
      enum { KEY_WORLD_68 = 228 };
      enum { KEY_WORLD_69 = 229 };
      enum { KEY_WORLD_70 = 230 };
      enum { KEY_WORLD_71 = 231 };
      enum { KEY_WORLD_72 = 232 };
      enum { KEY_WORLD_73 = 233 };
      enum { KEY_WORLD_74 = 234 };
      enum { KEY_WORLD_75 = 235 };
      enum { KEY_WORLD_76 = 236 };
      enum { KEY_WORLD_77 = 237 };
      enum { KEY_WORLD_78 = 238 };
      enum { KEY_WORLD_79 = 239 };
      enum { KEY_WORLD_80 = 240 };
      enum { KEY_WORLD_81 = 241 };
      enum { KEY_WORLD_82 = 242 };
      enum { KEY_WORLD_83 = 243 };
      enum { KEY_WORLD_84 = 244 };
      enum { KEY_WORLD_85 = 245 };
      enum { KEY_WORLD_86 = 246 };
      enum { KEY_WORLD_87 = 247 };
      enum { KEY_WORLD_88 = 248 };
      enum { KEY_WORLD_89 = 249 };
      enum { KEY_WORLD_90 = 250 };
      enum { KEY_WORLD_91 = 251 };
      enum { KEY_WORLD_92 = 252 };
      enum { KEY_WORLD_93 = 253 };
      enum { KEY_WORLD_94 = 254 };
      enum { KEY_WORLD_95 = 255 };
      enum { KEY_KP0 = 256 };
      enum { KEY_KP1 = 257 };
      enum { KEY_KP2 = 258 };
      enum { KEY_KP3 = 259 };
      enum { KEY_KP4 = 260 };
      enum { KEY_KP5 = 261 };
      enum { KEY_KP6 = 262 };
      enum { KEY_KP7 = 263 };
      enum { KEY_KP8 = 264 };
      enum { KEY_KP9 = 265 };
      enum { KEY_KP_PERIOD = 266 };
      enum { KEY_KP_DIVIDE = 267 };
      enum { KEY_KP_MULTIPLY = 268 };
      enum { KEY_KP_MINUS = 269 };
      enum { KEY_KP_PLUS = 270 };
      enum { KEY_KP_ENTER = 271 };
      enum { KEY_KP_EQUALS = 272 };
      enum { KEY_UP = 273 };
      enum { KEY_DOWN = 274 };
      enum { KEY_RIGHT = 275 };
      enum { KEY_LEFT = 276 };
      enum { KEY_INSERT = 277 };
      enum { KEY_HOME = 278 };
      enum { KEY_END = 279 };
      enum { KEY_PAGEUP = 280 };
      enum { KEY_PAGEDOWN = 281 };
      enum { KEY_F1 = 282 };
      enum { KEY_F2 = 283 };
      enum { KEY_F3 = 284 };
      enum { KEY_F4 = 285 };
      enum { KEY_F5 = 286 };
      enum { KEY_F6 = 287 };
      enum { KEY_F7 = 288 };
      enum { KEY_F8 = 289 };
      enum { KEY_F9 = 290 };
      enum { KEY_F10 = 291 };
      enum { KEY_F11 = 292 };
      enum { KEY_F12 = 293 };
      enum { KEY_F13 = 294 };
      enum { KEY_F14 = 295 };
      enum { KEY_F15 = 296 };
      enum { KEY_NUMLOCK = 300 };
      enum { KEY_CAPSLOCK = 301 };
      enum { KEY_SCROLLOCK = 302 };
      enum { KEY_RSHIFT = 303 };
      enum { KEY_LSHIFT = 304 };
      enum { KEY_RCTRL = 305 };
      enum { KEY_LCTRL = 306 };
      enum { KEY_RALT = 307 };
      enum { KEY_LALT = 308 };
      enum { KEY_RMETA = 309 };
      enum { KEY_LMETA = 310 };
      enum { KEY_LSUPER = 311 };
      enum { KEY_RSUPER = 312 };
      enum { KEY_MODE = 313 };
      enum { KEY_COMPOSE = 314 };
      enum { KEY_HELP = 315 };
      enum { KEY_PRINT = 316 };
      enum { KEY_SYSREQ = 317 };
      enum { KEY_BREAK = 318 };
      enum { KEY_MENU = 319 };
      enum { KEY_POWER = 320 };
      enum { KEY_EURO = 321 };
      enum { KEY_UNDO = 322 };
      enum { MODIFIER_NONE = 0 };
      enum { MODIFIER_LSHIFT = 1 };
      enum { MODIFIER_RSHIFT = 2 };
      enum { MODIFIER_LCTRL = 64 };
      enum { MODIFIER_RCTRL = 128 };
      enum { MODIFIER_LALT = 256 };
      enum { MODIFIER_RALT = 512 };
      enum { MODIFIER_LMETA = 1024 };
      enum { MODIFIER_RMETA = 2048 };
      enum { MODIFIER_NUM = 4096 };
      enum { MODIFIER_CAPS = 8192 };
      enum { MODIFIER_MODE = 16384 };
      enum { MODIFIER_RESERVED = 32768 };

    Key():
      header(),
      code(0),
      modifiers(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->code >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->code >> (8 * 1)) & 0xFF;
      offset += sizeof(this->code);
      *(outbuffer + offset + 0) = (this->modifiers >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->modifiers >> (8 * 1)) & 0xFF;
      offset += sizeof(this->modifiers);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      this->code =  ((uint16_t) (*(inbuffer + offset)));
      this->code |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->code);
      this->modifiers =  ((uint16_t) (*(inbuffer + offset)));
      this->modifiers |= ((uint16_t) (*(inbuffer + offset + 1))) << (8 * 1);
      offset += sizeof(this->modifiers);
     return offset;
    }

    const char * getType(){ return "keyboard/Key"; };
    const char * getMD5(){ return "5d57616b5631968b8f1d31d23c83281f"; };

  };

}
#endif