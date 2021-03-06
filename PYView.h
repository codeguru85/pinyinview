// PYView.h: Public Interface for PinyinView

#import <Cocoa/Cocoa.h>

// The resulting font size for pinyin text is
// font size for hanzi * kPinyinFontSizeRatio
#define kPinyinFontSizeRatio 0.35

// Border length in user space unit
#define kPinyinViewBorder    10

// The height between pinyin and hanzi
#define kPinyinHanziLeading  10

// The advance space ratio for hanzi
#define kFontAdvanceRatio    1.1

// The initial capacity of PYMarkerItem array
#define kMarkerItemsInitialCapacity 10

// The space between each marker item
#define kMarkerItemInterspacing 20

@interface PYMarkerItem : NSObject
{
    NSString *_han;
    NSArray	 *_py;
    int	      _type;
}

- (NSString *) hanzi;
- (NSArray *) pinyin;
- (int) type;

- (id) initWithHanzi: (NSString *) hanzi
              pinyin: (NSArray *) pinyin
                type: (int) type;

+ (id) itemWithHanzi: (NSString *) hanzi
              pinyin: (NSArray *) pinyin
                type: (int) type;

@end

@interface PYView : NSView
{
    NSMutableArray *_items;
    NSDictionary   *_hanAttributes;
    NSDictionary   *_pyAttributes;
    float           _size;
    float           _pinyinSize;
    float           _advance;
}

- (void) appendMarkerItem: (PYMarkerItem *) item;
- (void) clearMarkerItems;

- (id) initWithFrame: (NSRect) frameRect
            fontName: (NSString *) name
               color: (NSColor *) color;

@end
